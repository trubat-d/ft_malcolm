/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:15:16 by lord              #+#    #+#             */
/*   Updated: 2022/10/11 10:56:44 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = (void *)0;
	if (lst == (void *)0)
		return ((void *)0);
	head = ft_lstnew(f(lst->content));
	lst = lst->next;
	if (lst == (void *)0)
		return ((void *)0);
	node = ft_lstnew(f(lst->content));
	head->next = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		node = node->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	free(lst);
	return (head);
}
