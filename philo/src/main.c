/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 11:54:52 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/11 10:47:20 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (error_msg_invalid_input(ARGS));
	else
	{
		if (shared_data_init(&data, argc, argv) == 1)
			return (EXIT_FAILURE);
		if (start_diner(&data) == 1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
