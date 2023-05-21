/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 17:12:37 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/11 10:47:29 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == 48)
	{
		i++;
	}
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (neg * result);
}
