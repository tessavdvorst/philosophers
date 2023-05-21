/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:10:37 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/10 16:09:26 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_numeric(char *arg);
int		check_and_convert_arg(char *arg);

#endif