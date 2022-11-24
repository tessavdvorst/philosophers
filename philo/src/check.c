/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 14:36:47 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 15:19:39 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_anyone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->death_check);
	if (philo->shared_data->anyone_dead)
	{
		pthread_mutex_unlock(&philo->shared_data->death_check);
		return (true);
	}
	pthread_mutex_unlock(&philo->shared_data->death_check);
	return (false);
}

int	check_num_meals(t_philo *philo)
{
	int	num_of_philos;

	num_of_philos = philo->shared_data->num_of_philos;
	pthread_mutex_lock(&(philo->m_philo));
	if (philo->id == 0)
		printf(" 1 hi\n");
	if (philo->shared_data->min_meals
		&& philo->num_of_meals == philo->shared_data->min_meals)
	{
		philo->shared_data->finished_philos += 1;
		if (philo->shared_data->finished_philos == num_of_philos)
		{
			pthread_mutex_unlock(&(philo->m_philo));
			return (-1);
		}
		pthread_mutex_unlock(&(philo->m_philo));
		return (1);
	}
	pthread_mutex_unlock(&(philo->m_philo));
	return (0);
}

bool	check_satisfied(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_philo));
	if (philo->shared_data->min_meals
		&& philo->num_of_meals == philo->shared_data->min_meals)
	{
		pthread_mutex_unlock(&(philo->m_philo));
		return (true);
	}
	pthread_mutex_unlock(&(philo->m_philo));
	return (false);
}

bool	death_check_all(t_philo *philo)
{
	int			i;
	long long	elapsed_time;

	i = 0;
	while (i < philo->shared_data->num_of_philos)
	{
		pthread_mutex_lock(&(philo->m_philo));
		elapsed_time = get_timestamp() - philo->time_last_meal;
		pthread_mutex_unlock(&(philo->m_philo));
		if (elapsed_time >= philo->shared_data->time_to_die)
		{
			pthread_mutex_lock(&philo->shared_data->death_check);
			philo->shared_data->anyone_dead = true;
			pthread_mutex_unlock(&philo->shared_data->death_check);
			if (!check_satisfied(philo))
			{
				print_lock(DIE, philo);
				return (true);
			}
		}
		i++;
	}
	return (false);
}
