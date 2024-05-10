/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:42:28 by dolifero          #+#    #+#             */
/*   Updated: 2024/04/24 18:20:08 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_putptr_base(unsigned long nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	length;

	size_base = 0;
	i = 0;
	length = 0;
	while (base[size_base])
		size_base++;
	if (check_base(base))
	{
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

int	put_pointer(void *n)
{
	char			*base;
	int				length;
	unsigned long	number;

	number = (unsigned long)n;
	base = "0123456789abcdef";
	length = 0;
	write(1, "0x", 2);
	if (n == NULL)
	{
		write(1, "0", 1);
		return (3);
	}
	length = ft_putptr_base(number, base) + 2;
	return (length);
}
