/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd copy.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 14:11:12 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/10/10 16:14:48 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}
