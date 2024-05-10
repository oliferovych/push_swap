/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:56:58 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/15 15:12:49 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next_node;

	current = lst;
	if (lst == NULL)
		return ;
	while (current != NULL)
	{
		next_node = current -> next;
		f(current -> content);
		current = next_node;
	}
}
