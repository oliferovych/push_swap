/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:42:02 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/14 16:56:19 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	if (lst == NULL)
		return ;
	while (current != NULL)
	{
		next_node = current -> next;
		ft_lstdelone(current, *del);
		current = next_node;
	}
	*lst = NULL;
}
