/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:26:18 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/09 17:10:13 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i <= len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == (size_t)ft_strlen(needle) - 1)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char string[] = "hay hay hay hay needle hay";
// 	char needle[] = "needle";

// 	printf("%s", ft_strnstr(string, needle, 24));
// }
