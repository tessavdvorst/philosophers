/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:08:02 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 15:00:51 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_arr_init(t_data *data)
{
	int				i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (EXIT_FAILURE);
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	mutex_init(t_data *data)
{
	if (mutex_arr_init(data) == 1)
		return (error_msg_invalid_input(MUTEX_ARR));
	// if (pthread_mutex_init(&(data->last_meal), NULL) != 0)
	// 	return (error_msg_invalid_input(MUTEX));
	if (pthread_mutex_init(&(data->death_check), NULL) != 0)
		return (error_msg_invalid_input(MUTEX));
	// if (pthread_mutex_init(&(data->meal_check), NULL) != 0)
	// 	return (error_msg_invalid_input(MUTEX));
	return (EXIT_SUCCESS);
}

static int	meal_init(t_data *data, int argc, char *argv[])
{
	if (argc == 6)
	{
		data->min_meals = check_and_convert_arg(argv[5]);
		if (data->min_meals <= 0)
			return (error_msg_invalid_input(VAL));
	}
	else
		data->min_meals = 0;
	return (0);
}

int	shared_data_init(t_data *data, int argc, char *argv[])
{
	data->num_of_philos = check_and_convert_arg(argv[1]);
	if (data->num_of_philos <= 0)
		return (error_msg_invalid_input(VAL));
	data->time_to_die = check_and_convert_arg(argv[2]);
	if (data->time_to_die <= 0)
		return (error_msg_invalid_input(VAL));
	data->time_to_eat = check_and_convert_arg(argv[3]);
	if (data->time_to_eat <= 0)
		return (error_msg_invalid_input(VAL));
	data->time_to_sleep = check_and_convert_arg(argv[4]);
	if (data->time_to_sleep <= 0)
		return (error_msg_invalid_input(VAL));
	if (meal_init(data, argc, argv) == 1)
		return (EXIT_FAILURE);
	data->start_time = 0;
	data->finished_philos = 0;
	data->anyone_dead = false;
	if (mutex_init(data) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philo_init(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philo[i].id = i;
		philo[i].num_of_meals = 0;
		philo[i].left_fork = philo[i].id;
		philo[i].right_fork = (philo[i].id + 1) % data->num_of_philos;
		philo[i].time_last_meal = data->start_time;
		philo[i].shared_data = data;
		if (pthread_mutex_init(&(philo[i].m_philo), NULL) != 0)
			return (error_msg_invalid_input(MUTEX));
		i++;
	}
	return (EXIT_SUCCESS);
}
