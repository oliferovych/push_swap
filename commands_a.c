/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:33:34 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/05 19:16:20 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
