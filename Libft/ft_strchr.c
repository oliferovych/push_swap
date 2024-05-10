/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:20:26 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/12 14:46:38 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurrence of c in string.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("%s\n", ft_strchr("sallaba du \0ba", '\0'));
// 	printf("%s\n", strchr("sallaba du \0ba", '\0'));
// 	return (0);
// }
