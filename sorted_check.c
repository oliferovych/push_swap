/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:59:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/03 18:06:16 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_is_sorted(t_stack *a)
{
	int	i;
	int	*arr;
	int	len;

	i = 1;
	arr = a->stack;
	len = a->len;
	while (i < len)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}
