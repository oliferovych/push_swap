/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:16:28 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/16 16:42:16 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dst[i] != '\0')
		dst[i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	// char destination[20] = "hi";
// 	// const char *source = "world!";

// 	// size_t result = strlcat(destination, source, 0);
// 	// printf("Concatenated string: %s\n", destination);
// 	// printf("Total length: %zu\n", result);
// 	// char ndestination[20];
// 	// result = ft_strlcat(ndestination, source, 0);
// 	// printf("\nConcatenated string: %s\n", ndestination);
// 	// printf("Total length: %zu\n", result);
// 	// return (0);
//     char	*dest;
// 	dest[10] = 'a';
// 	ft_strlcat(dest, "lorem ipsum dolor sit amet", 6);
//     printf("result: %s\n", dest);
//     write(1, "\n", 1);
//     write(1, dest, 15);
// }
