/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:22 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/10 15:41:44 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_square_root(int nbr)
{
	int	i;

	if (nbr < 4)
		return (1);
	i = 2;
	while (i * i < nbr)
		i++;
	if (i * i > nbr)
	{
		if ((i * i - nbr) < ((i - 1) * (i - 1) + (-nbr)))
			return (i);
	}
	return (i - 1);
}

void	sort_while_to_b(t_stack *a, t_stack *b)
{
	int	j;
	int	srange;

	srange = get_square_root(a->len) * 13 / 10;
	j = 0;
	while (a->len > 0)
	{
		if (a->stack[0] <= j)
		{
			push_b(b, a);
			rotate_b(b);
			j++;
		}
		if (a->stack[0] <= j + srange)
		{
			push_b(b, a);
			j++;
		}
		else
			rotate_a(a);
	}
}

int	count_rb(t_stack *b)
{
	int	i;

	i = 0;
	while (i <= b->len - 2 && b->stack[i] != b->len)
	{
		i++;
	}
	return (i);
}

void	sort_while_to_a(t_stack *a, t_stack *b)
{
	int	rb_count;
	int	rrb_count;
	int	j;

	while (b->len > 0)
	{
		rb_count = count_rb(b);
		rrb_count = (b->len + 3) - rb_count;
		j = 0;
		if (rb_count <= rrb_count)
		{
			while (b->stack[j] - 1 != b->len - 1)
				rotate_b(b);
			push_a(a, b);
		}
		else
		{
			while (b->stack[j] - 1 != b->len - 1)
				reverse_rotate_b(b);
			push_a(a, b);
		}
	}
}
