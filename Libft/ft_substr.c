/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:55:19 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/11 17:48:33 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char *s = "Hello, World!";

// 	char *sub = ft_substr(s, 3, 13);

// 	if (sub)
// 	{
// 		printf("Substring: %s\n", sub);
// 		printf("Length of substring: %zu\n", strlen(sub));
// 		free(sub);
// 	}
// 	else
// 	{
// 		printf("Substring creation failed!\n");
// 	}

// 	return (0);
// }
