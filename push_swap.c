/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:40:44 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/10 16:12:28 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_nest(t_stackset *stacks)
{
	if (stacks->a.len == 2)
		swap_a(&stacks->a);
	else if (stacks->a.len == 3)
		three_elements(&stacks->a);
	else if (stacks->a.len > 3 && stacks->a.len <= 5)
		five_elements(&stacks->a, &stacks->b);
	else
	{
		sort_while_to_b(&stacks->a, &stacks->b);
		sort_while_to_a(&stacks->a, &stacks->b);
	}
}

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack		input;
	t_stackset	*stacks;

	if (!parse_input(argc, argv, &input))
		return (1);
	if (array_is_sorted(&input))
		return (free(input.stack), 0);
	stacks = malloc(sizeof(t_stackset));
	if (!stacks)
		return (free(input.stack), ft_putstr_fd("Error\n", 2), 0);
	ft_allocate_stacks(stacks, input.stack, input.len);
	bubble_sort(&stacks->a);
	indexing(&(stacks->input), &(stacks->a));
	ft_memcpy(stacks->a.stack, stacks->input.stack, sizeof(int) * (input.len));
	sorting_nest(stacks);
	free_everything(stacks);
	return (0);
}
