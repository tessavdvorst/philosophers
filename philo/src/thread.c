/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 15:00:23 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 15:09:41 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philo, pthread_t *thread, t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_timestamp();
	if (philo_init(data, philo) != 0)
		return (EXIT_FAILURE);
	while (i < data->num_of_philos)
	{
		if (pthread_create(&thread[i], NULL, &routine, &philo[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	join_philo_threads(pthread_t *thread, t_data *data)
{
	int	i;

	i = 0;
	if (data->num_of_philos == 1)
	{
		if (pthread_detach(thread[i]) != 0)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	while (i < data->num_of_philos)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	destroy_all_mutex(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&(philo[i].m_philo));
		i++;
	}
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&data->death_check);
	// pthread_mutex_destroy(&data->last_meal);
	// pthread_mutex_destroy(&data->meal_check);
}

void	free_all(t_data *data, pthread_t *thread, t_philo *philo)
{
	free(thread);
	free(philo);
	free(data->forks);
}
