/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:14:12 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 20:05:09 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*concatenated;

	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	concatenated = malloc(total_len + 1);
	if (concatenated == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(concatenated, s1, s1_len + 1);
	else
		concatenated[0] = '\0';
	if (s2 != NULL)
		ft_strlcat(concatenated, s2, total_len + 1);
	return (concatenated);
}
