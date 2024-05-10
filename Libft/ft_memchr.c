/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:34:53 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/11 13:26:49 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*array;
	size_t				i;

	array = s;
	i = 0;
	while (i < n)
	{
		if (array[i] == (unsigned char)c)
			return ((void *)&array[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", (char *)ft_memchr("Oh this wonderful morning", 'm', 25));
// 	return (0);
// }
