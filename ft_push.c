/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:37:32 by rradules          #+#    #+#             */
/*   Updated: 2024/05/13 15:12:35 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_cont **host, t_cont **newcomer, int push)
{
	int		newnode;
	t_cont	*head_newcomer;
	t_cont	*head_host;

	newnode = (*newcomer)->content;
	head_newcomer = (*newcomer)->next;
	free(*newcomer);
	*newcomer = head_newcomer;
	head_host = ft_newnode(newnode);
	head_host->next = *host;
	*host = head_host;
	if (push == 0)
		ft_printf("pa\n");
	else if (push == 1)
		ft_printf("pb\n");
}
