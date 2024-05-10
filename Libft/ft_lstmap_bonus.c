/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:52 by dolifero          #+#    #+#             */
/*   Updated: 2024/04/24 18:19:29 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_node;
	void	*content_result;

	newlist = NULL;
	if (lst == NULL || !f || !del)
		return (NULL);
	while (lst)
	{
		content_result = f(lst -> content);
		new_node = ft_lstnew(content_result);
		if (new_node == NULL)
		{
			del(content_result);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, new_node);
		lst = lst -> next;
	}
	return (newlist);
}
