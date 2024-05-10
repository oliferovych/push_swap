/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:35:14 by dolifero          #+#    #+#             */
/*   Updated: 2024/04/24 18:17:41 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd1(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == (char *) NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
