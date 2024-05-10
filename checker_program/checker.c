/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:43:15 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/06 15:30:36 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	if_nest(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(line, "ra\n", 4))
		rotate(a);
	else if (!ft_strncmp(line, "rra\n", 5))
		reverse_rotate(a);
	else if (!ft_strncmp(line, "pa\n", 4))
		push(a, b);
	else if (!ft_strncmp(line, "sb\n", 4))
		swap(b);
	else if (!ft_strncmp(line, "rb\n", 4))
		rotate(b);
	else if (!ft_strncmp(line, "rrb\n", 5))
		reverse_rotate(b);
	else if (!ft_strncmp(line, "pb\n", 4))
		push(b, a);
	else if (!ft_strncmp(line, "ss\n", 4))
		return (swap(a), swap(b));
	else if (!ft_strncmp(line, "rr\n", 4))
		return (rotate(a), rotate(b));
	else if (!ft_strncmp(line, "rrr\n", 5))
		return (reverse_rotate(a), reverse_rotate(b));
	else
		return (ft_printf("Error"), exit(1));
}

int	a_srtd_b_mt(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	while (i < a->len)
	{
		if (a->stack[i - 1] > a->stack[i])
			return (free(a->stack), free(b->stack), ft_putstr_fd("KO\n", 2), 1);
		i++;
	}
	if (b->len > 0)
		return (free(a->stack), free(b->stack), ft_putstr_fd("KO\n", 2), 1);
	return (free(a->stack), free(b->stack), ft_putstr_fd("OK\n", 2), 0);
}

// void	leaks(void)
// {
// 	system("leaks checker");
// }

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (!parse_a(argc, argv, &a))
		return (1);
	b.stack = (int *)malloc(sizeof(int) * a.len);
	b.len = 0;
	line = get_next_line(0);
	while (line[0] != '\n')
	{
		if_nest(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	free (line);
	return (a_srtd_b_mt(&a, &b));
}

	// ft_printf("Length of array a: %d\n", a.len);
	// int i;
	// for (i = 0; i < a.len; i++)
	// 	ft_printf("a[%d]: %d\n", i, a.stack[i]);
	// ft_printf("Length of array b: %d\n", b.len);
	// for (i = 0; i < b.len; i++)
	// 	ft_printf("b[%d]: %d\n", i, b.stack[i]);
