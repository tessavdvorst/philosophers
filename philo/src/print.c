/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:34:25 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 15:09:16 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int state, t_philo *philo)
{
	// long long	timestamp;
	const char	*print_msg[]
		= {
		" has taken a fork",
		" is eating",
		" is sleeping",
		" is thinking",
		" died"
	};

	// timestamp = time_since_start(philo->shared_data->start_time);
	printf("%-6lld %-4d %s\n", time_since_start(philo->shared_data->start_time), philo->id + 1,
		(char *)print_msg[state]);
}

void	print_lock(int state, t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->death_check);
	if (philo->shared_data->anyone_dead == false)
	{
		if (state == EAT)
		{
			pthread_mutex_lock(&(philo->m_philo));
			philo->time_last_meal = get_timestamp();
			pthread_mutex_unlock(&(philo->m_philo));
		}
		print_state(state, philo);
	}
	else if (state == DIE)
	{
		print_state(state, philo);
		philo->shared_data->anyone_dead = true;
	}
	pthread_mutex_unlock(&philo->shared_data->death_check);
}
