/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_numeric.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 12:13:28 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/02 12:52:31 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_numeric(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] == ' ')
		i++;
	if (arg[i] && (arg[i] == '+' || arg[i] == '-'))
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i])
		return (0);
	return (1);
}
