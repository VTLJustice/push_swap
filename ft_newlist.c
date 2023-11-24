/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:08:06 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:14:46 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cont	*ft_newlist(int	*content)
{
	t_cont	*head;

	head = malloc(sizeof(int));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
