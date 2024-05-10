/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:19:35 by dolifero          #+#    #+#             */
/*   Updated: 2024/05/08 18:35:28 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	one_string_a(char *argument, t_stack *a)
{
	int		i;
	int		j;
	char	**splitted;

	i = 0;
	j = 0;
	splitted = ft_split(argument, ' ');
	while (splitted[j])
		j++;
	a->stack = (int *)malloc(sizeof(int) * j);
	a->len = j;
	while (splitted[i])
	{
		if (!str_is_numerical(splitted[i]) || !fits_in_int(splitted[i]))
			return (free(a->stack), ft_putstr_fd("Error", 2), 0);
		a->stack[i] = ft_atoi(splitted[i]);
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (1);
}

int	multiple_strings_a(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	a->stack = (int *)malloc(sizeof(int) * (argc - 1));
	while (++i < argc)
	{
		if (!str_is_numerical(argv[i]) || !fits_in_int(argv[i]))
			return (free(a->stack), ft_putstr_fd("Error", 2), 0);
		a->stack[i - 1] = ft_atoi(argv[i]);
	}
	a->len = argc - 1;
	return (1);
}

int	parse_a(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_putstr_fd("Error", 2), 0);
	if (argc == 2)
	{
		if (!one_string_a(argv[1], a))
			return (0);
	}
	else
	{
		if (!multiple_strings_a(argc, argv, a))
			return (0);
	}
	if (doubles(*a))
		return (free(a->stack), ft_putstr_fd("Error", 2), 0);
	return (1);
}
