/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:34:02 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/02 15:05:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_special_cases(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_putnbr_fd1(int n, int fd)
{
	int	i;
	int	length;
	int	container[11];

	i = 0;
	length = print_special_cases(n, fd);
	if (length == 0)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			length++;
			n *= (-1);
		}
		while (n != 0)
		{
			container[i] = n % 10;
			n = n / 10;
			i++;
		}
		length += i;
		while (--i >= 0)
			ft_putchar_fd(container[i] + '0', fd);
	}
	return (length);
}

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	i;
	int	length;
	int	container[11];

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (n != 0)
	{
		container[i] = n % 10;
		n = n / 10;
		i++;
	}
	length = i;
	while (--i >= 0)
		ft_putchar_fd(container[i] + '0', fd);
	return (length);
}

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	length;

	i = 0;
	length = 0;
	size_base = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		length = i;
		while (--i >= 0)
			ft_putchar_fd(base[nbr_final[i]], 1);
	}
	return (length);
}
