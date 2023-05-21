/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:59:30 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/24 12:23:31 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	error_msg_invalid_input(int err)
{
	const char	*err_msg[]
		= {
		"invalid amount of arguments\n",
		"array of mutexes are not initialized\n",
		"mutexes are not initialized\n",
		"only insert values that are numerical, positive and at least 1\n",
	};

	ft_putstr_fd("error: ", STDERR_FILENO);
	ft_putendl_fd((char *)err_msg[err], STDERR_FILENO);
	ft_putendl_fd("usage: ./philo\t[num_of_philosophers] [time_to_die]",
		STDERR_FILENO);
	ft_putendl_fd("\t\t[time_to_eat] [time_to_sleep]", STDERR_FILENO);
	ft_putendl_fd("\t\t[number_of_times_each_philosopher_must_eat] (optional)\n",
		STDERR_FILENO);
	ft_putendl_fd("example: ./philo 3 410 200 200", STDERR_FILENO);
	return (1);
}
