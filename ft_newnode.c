/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:08:06 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 17:21:25 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cont	*ft_newnode(int content)
{
	t_cont	*head;

	head = malloc(sizeof(t_cont));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
