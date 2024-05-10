/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:29:56 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 19:43:06 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_allocate_stacks(t_stackset *stacks, int *input, int length)
{
	stacks->input.stack = input;
	stacks->input.len = length;
	stacks->a.stack = (int *)malloc(sizeof(int) * length);
	if (!stacks->a.stack)
	{
		free(stacks->input.stack);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stacks->a.len = length;
	stacks->b.stack = (int *)malloc(sizeof(int) * length);
	if (!stacks->b.stack)
	{
		free(stacks->input.stack);
		free(stacks->a.stack);
		free(stacks);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stacks->b.len = 0;
	ft_memcpy(stacks->a.stack, stacks->input.stack, sizeof(int) * length);
}

void	free_everything(t_stackset *stacks)
{
	free(stacks->a.stack);
	free(stacks->b.stack);
	free(stacks->input.stack);
	free(stacks);
}
