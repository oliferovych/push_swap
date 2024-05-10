/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:40:41 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/10 15:49:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int	len;
	int	*stack;
}				t_stack;

typedef struct s_stackset
{
	t_stack	a;
	t_stack	b;
	t_stack	input;
}				t_stackset;

int		parse_input(int argc, char **argv, t_stack *input);
void	ft_allocate_stacks(t_stackset *stacks, int *input, int length);
void	free_everything(t_stackset *stacks);

void	bubble_sort(t_stack *a);
void	indexing(t_stack *input, t_stack *a);
void	three_elements(t_stack *a);
void	five_elements(t_stack *a, t_stack *b);

void	sort_while_to_b(t_stack *a, t_stack *b);
void	sort_while_to_a(t_stack *a, t_stack *b);

int		str_is_numerical(char *string);
int		doubles(t_stack a);
int		fits_in_int(const char *str);
int		array_is_sorted(t_stack *a);

void	swap(t_stack *x);
void	push(t_stack *x, t_stack *z);
void	rotate(t_stack *x);
void	reverse_rotate(t_stack *x);

void	swap_a(t_stack *a);
void	push_a(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	reverse_rotate_a(t_stack *a);

void	swap_b(t_stack *b);
void	push_b(t_stack *b, t_stack *a);
void	rotate_b(t_stack *b);
void	reverse_rotate_b(t_stack *b);

void	swap_both(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);

#endif
