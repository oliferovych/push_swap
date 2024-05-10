/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:43:18 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/05 18:14:09 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include "../push_swap.h"

// typedef struct s_stack
// {
// 	int	len;
// 	int	*stack;
// }				t_stack;

void	swap_a(t_stack *a);
void	push_a(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	reverse_rotate_a(t_stack *a);

void	swap_b(t_stack *b);
void	push_b(t_stack *b, t_stack *a);
void	rotate_b(t_stack *b);
void	reverse_rotate_b(t_stack *b);

int		parse_a(int argc, char **argv, t_stack *a);

#endif
