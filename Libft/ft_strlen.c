/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:15:53 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/07 15:00:52 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

// #include <stdio.h>
// int main(void)
// {
// 	char string[] = "tvoya mama suka";
// 	printf("%d", ft_strlen(string));
// }
