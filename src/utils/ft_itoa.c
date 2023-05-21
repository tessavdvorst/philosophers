/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 12:13:14 by Tessa         #+#    #+#                 */
/*   Updated: 2022/11/02 11:33:21 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

int	len_int(int n)
{
	int			i;
	int			tmp;
	long long	x;

	x = n;
	tmp = x;
	if (check_neg(x) == 1)
	{
		x = x * -1;
	}
	if (x == 0)
	{
		return (1);
	}
	i = 0;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	if (check_neg(tmp) == 1)
		return (i + 1);
	else
		return (i);
}

char	*itoa(int n, char *s)
{
	int			i;
	int			len;
	long long	x;

	x = n;
	len = len_int(x);
	i = len - 1;
	if (x == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (check_neg(x) == 1)
	{
		s[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		s[i] = (x % 10) + '0';
		x = x / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = len_int(n);
	str = ft_calloc((len + 1), (sizeof(char)));
	if (!str)
		return (NULL);
	itoa(n, str);
	return (str);
}
