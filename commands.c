/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:04:06 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/05 18:19:21 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *x)
{
	int	container;

	if (x->len > 1)
	{
		container = x->stack[0];
		x->stack[0] = x->stack[1];
		x->stack[1] = container;
	}
}

void	push(t_stack *x, t_stack *z)
{
	int	i;

	if (x->stack != NULL && z->len > 0 && x->len >= 0)
	{
		i = x->len - 1;
		while (i >= 0)
		{
			x->stack[i + 1] = x->stack[i];
			i--;
		}
		x->stack[0] = z->stack[0];
		i = 0;
		while (i < z->len - 1)
		{
			z->stack[i] = z->stack[i + 1];
			i++;
		}
		z->len -= 1;
		x->len += 1;
	}
}

void	rotate(t_stack *x)
{
	int	container;
	int	i;

	i = 1;
	container = x->stack[0];
	while (i < x->len)
	{
		x->stack[i - 1] = x->stack[i];
		i++;
	}
	x->stack[(x->len) - 1] = container;
}

void	reverse_rotate(t_stack *x)
{
	int	container;
	int	i;

	container = x->stack[(x->len) - 1];
	i = x->len;
	while (i-- > 0)
		x->stack[i] = x->stack[i - 1];
	x->stack[0] = container;
}
