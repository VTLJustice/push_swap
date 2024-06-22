/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:05:58 by rradules          #+#    #+#             */
/*   Updated: 2024/03/05 15:11:57 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cont	*ft_lstlast(t_cont *lst)
{
	if (lst != NULL)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lst_addback(t_cont **lst, int content)
{
	t_cont	*last;
	t_cont	*node;

	if (*lst == NULL)
		*lst = ft_newnode(content);
	else
	{
		last = ft_lstlast(*lst);
		node = ft_newnode(content);
		last->next = node;
		node->prev = last;
	}
}
