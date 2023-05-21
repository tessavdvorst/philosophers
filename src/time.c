/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:51:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/10 16:34:32 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_timestamp(void)
{
	long long			miliseconds;
	struct timeval		current_time;

	miliseconds = 0;
	gettimeofday(&current_time, NULL);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec * 0.001);
	return (miliseconds);
}

long long	check_time_to_die(struct timeval start)
{
	long long			diff_miliseconds;
	long long			start_miliseconds;

	start_miliseconds = (start.tv_sec * 1000) + (start.tv_usec * 0.001);
	diff_miliseconds = get_timestamp() - start_miliseconds;
	return (diff_miliseconds);
}

long long	time_since_start(long long start_time)
{
	return (get_timestamp() - start_time);
}

bool	safe_sleep(t_philo *philo, long miliseconds)
{
	long long	start_time;

	start_time = get_timestamp();
	while (get_timestamp() - start_time < miliseconds)
	{
		usleep(100);
		if (check_anyone_dead(philo))
			return (false);
	}
	return (true);
}
