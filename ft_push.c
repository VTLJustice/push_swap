/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:37:32 by rradules          #+#    #+#             */
/*   Updated: 2024/03/05 12:52:43 by rradules         ###   ########.fr       */
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
		printf("pa\n");
	else if (push == 1)
		printf("pb\n");
}
