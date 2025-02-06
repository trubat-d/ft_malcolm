/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:36:05 by lord              #+#    #+#             */
/*   Updated: 2022/10/10 10:49:04 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*check;

	check = *lst;
	if (check == (void *)0)
		*lst = new;
	else
	{
		while ((check)->next != (void *)0)
		{
			check = ((check)->next);
		}
		(check)->next = new;
	}
}
