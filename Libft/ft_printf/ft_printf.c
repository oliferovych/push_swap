/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:34:26 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/02 15:07:09 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	char	*lowercase;
	char	*uppercase;
	int		length;

	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	length = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (c == 'X')
		length = ft_putnbr_base(n, uppercase);
	else
		length = ft_putnbr_base(n, lowercase);
	return (length);
}

int	format_check(char after_perc, va_list args, int fd)
{
	int	add_length;

	add_length = 0;
	if (after_perc == '%')
		add_length = ft_putchar_fd1('%', fd);
	else if (after_perc == 'c')
		add_length = ft_putchar_fd1(va_arg(args, int), fd);
	else if (after_perc == 's')
		add_length = ft_putstr_fd1(va_arg(args, char *), fd);
	else if (after_perc == 'p')
		add_length = put_pointer(va_arg(args, void *));
	else if (after_perc == 'd')
		add_length = ft_putnbr_fd1(va_arg(args, int), fd);
	else if (after_perc == 'i')
		add_length = ft_putnbr_fd1(va_arg(args, int), fd);
	else if (after_perc == 'u')
		add_length = ft_putunsigned_fd(va_arg(args, unsigned int), fd);
	else if (after_perc == 'x' || after_perc == 'X')
		add_length = ft_puthex(va_arg(args, unsigned int), after_perc);
	return (add_length);
}

int	ft_printf(const char *mod_string, ...)
{
	int		i;
	int		j;
	int		add_length;
	va_list	args;

	i = 0;
	j = 0;
	add_length = 0;
	va_start(args, mod_string);
	while (mod_string[i])
	{
		if (mod_string[i] == '%')
		{
			i++;
			add_length += format_check(mod_string[i], args, 1);
			j += 2;
		}
		else
			ft_putchar_fd(mod_string[i], 1);
		i++;
	}
	va_end(args);
	return (i - j + add_length);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	my_print;
// 	int	their_print;

// 	my_print = ft_printf("%X", 13124);
// 	ft_printf("\nNumber of chars printed(supposingly): %i\n", my_print);
// 	their_print = printf("%X", 13124);
// 	printf("\nNumber of chars printed(supposingly): %i\n", their_print);
// 	return (0);
// }
