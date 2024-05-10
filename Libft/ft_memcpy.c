/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:30:56 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 15:18:12 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	if (dst == NULL && src == NULL && n)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (i < n)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	source[] = "Hello, world!";
// 	char	destination[20];

// 	printf("Source: %s\n", source);
// 	printf("Destination before: %s\n", destination);
// 	ft_memcpy(destination, source, 8);
// 	printf("Copied string: %s\n", destination);
// 	return (0);
// }
