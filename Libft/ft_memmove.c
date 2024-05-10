/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:57:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/08 16:42:53 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = (char *)dst;
	source = (const char *)src;
	if (dest < source)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else if (dest > source)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	target[] = "learning is fun";
// 	char	*p = target + 15;
// 	char	*source = target + 9;
// 	printf("Before memmove, target is \"%s\"\n", target);
// 	ft_memmove(p, source, 6);
// 	printf("After memmove, target becomes \"%s\"\n", target);
// }
