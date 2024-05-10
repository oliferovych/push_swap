/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:10:50 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/08 16:50:31 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclength;

	i = 0;
	srclength = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[srclength])
		srclength++;
	return (srclength);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dst[20];
// 	char	dst_std[20];

// 	printf("Source string: %s\n", src);
// 	printf("Initial destination string: %s\n", dst);
// 	size_t copied_length = ft_strlcpy(dst, src, sizeof(dst));

// 	printf("Copied string: %s\n", dst);
// 	printf("Length of copied string: %zu\n", copied_length);

// 	printf("\nSource string: %s\n", src);
// 	printf("Initial standard function destination string: %s\n", dst_std);
// 	size_t cpy_len_std = strlcpy(dst_std, src, sizeof(dst_std));
// 	printf("Standard Library Copied string: %s\n", dst_std);
// 	printf("Length of copied string: %zu\n", cpy_len_std);
// 	return (0);
// }
