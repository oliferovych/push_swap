/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 15:51:18 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_sign(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

static char	*ft_strnumcr(int i, int n)
{
	int		counter;
	char	*string;

	counter = i;
	string = malloc(i + 1);
	if (!string)
		return (NULL);
	while (n != 0 && i-- > 0)
	{
		string[i] = n % 10 + '0';
		n /= 10;
	}
	string[counter] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*string;
	int		sign;

	i = count_digits(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	n = ft_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	string = ft_strnumcr(i + sign, n);
	if (!string)
		return (NULL);
	if (sign)
		string[0] = '-';
	return (string);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_itoa(123213));
// 	return (0);
// }
