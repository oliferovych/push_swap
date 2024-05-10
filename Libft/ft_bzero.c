/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:30:10 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/06 19:25:30 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*arr;

	arr = s;
	if (n == 0)
		return ;
	while (n)
	{
		*arr++ = '\0';
		n--;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[20] = "heeloo";
// 	size_t	len;
// 	len = 10;
// 	printf("Original string: %s\n", str);
// 	ft_bzero(str, len);
// 	printf("After bzero: %s\n", str);
// 	return (0);
// }
