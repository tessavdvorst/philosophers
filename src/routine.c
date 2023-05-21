/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:50:39 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 18:35:01 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->forks[philo->left_fork]);
	print_lock(FORK, philo);
	pthread_mutex_lock(&philo->shared_data->forks[philo->right_fork]);
	print_lock(FORK, philo);
	print_lock(EAT, philo);
	if (philo->shared_data->min_meals)
	{
		pthread_mutex_lock(&(philo->m_philo));
		philo->num_of_meals += 1;
		pthread_mutex_unlock(&(philo->m_philo));
	}
	if (!safe_sleep(philo, philo->shared_data->time_to_eat))
	{
		pthread_mutex_unlock(&philo->shared_data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->shared_data->forks[philo->right_fork]);
		return (true);
	}
	pthread_mutex_unlock(&philo->shared_data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->shared_data->forks[philo->right_fork]);
	return (false);
}

static bool	philo_sleep_think(t_philo *philo)
{
	print_lock(SLEEP, philo);
	if (safe_sleep(philo, philo->shared_data->time_to_sleep))
		return (false);
	print_lock(THINK, philo);
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	while (!check_anyone_dead(philo))
	{
		if (philo_eat(philo))
			return (NULL);
		if (check_num_meals(philo))
			return (NULL);
		if (philo_sleep_think(philo))
			return (NULL);
	}
	return (NULL);
}

static void	monitor(t_philo *philo)
{
	while (1)
	{
		if (check_all_philos_finished(philo) != 0)
			return ;
		if (death_check_all(philo))
			return ;
		usleep(100);
	}
}

int	start_diner(t_data *data)
{
	t_philo			*philo;
	pthread_t		*thread;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_of_philos);
	if (!philo)
		return (EXIT_FAILURE);
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philos);
	if (!thread)
		return (EXIT_FAILURE);
	if (create_philo_threads(philo, thread, data) != 0)
		return (EXIT_FAILURE);
	monitor(philo);
	if (join_philo_threads(thread, data) != 0)
		return (EXIT_FAILURE);
	destroy_all_mutex(data, philo);
	free_all(data, thread, philo);
	return (EXIT_SUCCESS);
}
