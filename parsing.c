/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:19:35 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/10 16:15:02 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **splitted, int i)
{
	while (splitted[i] != 0)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int	one_string(char *argument, t_stack *input)
{
	int		i;
	int		j;
	char	**splitted;

	i = 0;
	j = 0;
	splitted = ft_split(argument, ' ');
	while (splitted[j])
		j++;
	input->stack = (int *)malloc(sizeof(int) * j);
	input->len = j;
	while (splitted[i])
	{
		if (!str_is_numerical(splitted[i]) || !fits_in_int(splitted[i]))
		{
			free_split(splitted, i);
			return (free(input->stack), ft_putstr_fd("Error\n", 2), 0);
		}
		input->stack[i] = ft_atoi(splitted[i]);
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (1);
}

int	multiple_strings(int argc, char **argv, t_stack *input)
{
	int	i;

	i = 0;
	input->stack = (int *)malloc(sizeof(int) * (argc - 1));
	while (++i < argc)
	{
		if (!str_is_numerical(argv[i]) || !fits_in_int(argv[i]))
			return (free(input->stack), ft_putstr_fd("Error\n", 2), 0);
		input->stack[i - 1] = ft_atoi(argv[i]);
	}
	input->len = argc - 1;
	return (1);
}

int	parse_input(int argc, char **argv, t_stack *input)
{
	if (argc < 2)
	{
		free(input->stack);
		return (1);
	}
	if (argc == 2)
	{
		if (!one_string(argv[1], input))
			return (0);
	}
	else
	{
		if (!multiple_strings(argc, argv, input))
			return (0);
	}
	if (doubles(*input))
		return (free(input->stack), ft_putstr_fd("Error\n", 2), 0);
	return (1);
}
