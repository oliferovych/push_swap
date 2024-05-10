/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:58 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/08 16:28:02 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*arr;

	arr = dest;
	while (len)
	{
		*arr++ = (unsigned char)c;
		len--;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[20];
// 	size_t	len;
// 	int		c;

// 	len = 10;
// 	c = 'X';
// 	printf("Original string: %s\n", str);
// 	ft_memset(str, c, len);
// 	printf("After memset: %s\n", str);

// 	return (0);
// }
