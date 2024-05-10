/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:33:49 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/08 17:29:30 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	push_b(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
