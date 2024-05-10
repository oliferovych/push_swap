/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:07:10 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/23 16:29:11 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	front = 0;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	if (!s1[front])
		return (ft_strdup(""));
	back = ft_strlen(s1) - 1;
	while (s1[back] && ft_strchr(set, s1[back]))
		back--;
	s2 = malloc((back - front + 1 + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + front, back - front + 1 + 1);
	return (s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "   \t \n  \t\n    ";
// 	printf("%s", ft_strtrim(s1, " \t\n"));
// }
