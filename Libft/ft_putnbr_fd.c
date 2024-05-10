/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:26:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/09 13:02:52 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		container[11];

	i = 0;
	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
			write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= (-1);
	}
	while (n != 0)
	{
		container[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(container[i] + '0', fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(1231, 1);
// 	return (0);
// }
