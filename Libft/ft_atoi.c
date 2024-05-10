/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:10:09 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 15:50:25 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	negativity;
	int	result;

	negativity = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			negativity *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * negativity);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_atoi("       --1231314"));
// 	printf("%d\n", ft_atoi("       214aksdjn7483647"));
// 	printf("%d\n", ft_atoi("       +1231314"));
// 	printf("%d\n", ft_atoi("       -0"));
// }
