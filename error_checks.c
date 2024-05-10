/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:11:19 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/08 18:03:19 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_is_numerical(char *string)
{
	int	i;

	i = 0;
	if (string[0] == ' ')
		return (0);
	while ((string[i] >= '0' && string[i] <= '9') || (string[i] == '-'
			&& (string[i + 1] >= '0' && string[i + 1] <= '9'))
		|| (string[i] == '+' && (string[i + 1] >= '0' && string[i + 1] <= '9')))
		i++;
	if (i != ft_strlen(string))
		return (0);
	return (1);
}

int	doubles(t_stack input)
{
	int	i;
	int	j;

	i = 0;
	while (i < input.len)
	{
		j = i + 1;
		while (j < input.len)
		{
			if (input.stack[i] == input.stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fits_in_int(const char *str)
{
	int			sign;
	int			i;
	long long	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str == NULL || *str == '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-')
		if (str[0] == '-')
			sign = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			if ((sign == 1 && num > INT_MAX) || (sign == -1 && num
					* (-1) < INT_MIN))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
