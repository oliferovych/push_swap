/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:57:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 17:18:48 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < a->len - 1)
	{
		j = i;
		while (++j < a->len)
		{
			if (a->stack[i] > a->stack[j])
			{
				temp = a->stack[i];
				a->stack[i] = a->stack[j];
				a->stack[j] = temp;
			}
		}
	}
}

void	indexing(t_stack *input, t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < input->len)
	{
		j = -1;
		while (++j < a->len)
		{
			if (input->stack[i] == a->stack[j])
			{
				input->stack[i] = j + 1;
				break ;
			}
		}
	}
}

void	three_elements(t_stack *a)
{
	while (!array_is_sorted(a))
	{
		if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
			swap_a(a);
		else if (a->stack[0] > a->stack[1])
			swap_a(a);
		else if (!array_is_sorted(a))
			reverse_rotate_a(a);
	}
}

void	five_elements(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	while (a->len > 3)
	{
		while (a->stack[0] != i)
		{
			if (i == a->stack[a->len - 1])
				reverse_rotate_a(a);
			else
				rotate_a(a);
		}
		push_b(b, a);
		i++;
	}
	three_elements(a);
	push_a(a, b);
	push_a(a, b);
}
