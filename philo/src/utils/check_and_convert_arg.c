/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_convert_arg.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 12:13:50 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/10 17:30:24 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_and_convert_arg(char *arg)
{
	int		num;
	int		result;
	char	*conversion;

	if (check_numeric(arg))
	{
		num = ft_atoi(arg);
		conversion = ft_itoa(num);
		result = ft_strncmp(arg, conversion, ft_strlen(arg));
		free(conversion);
		if (result == 0)
			return (num);
	}
	return (-1);
}
