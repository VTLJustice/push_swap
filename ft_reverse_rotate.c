/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:07:27 by rradules          #+#    #+#             */
/*   Updated: 2024/05/13 15:13:19 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_cont **stack, int reverse_rotate)
{
	t_cont	*tempnode;
	t_cont	*head;

	head = NULL;
	tempnode = (*stack);
	while (tempnode)
	{
		if (tempnode->next->next == NULL)
		{
			head = tempnode->next;
			tempnode->next = NULL;
			break ;
		}
		else
			tempnode = tempnode->next;
	}
	head->next = (*stack);
	(*stack) = head;
	if (reverse_rotate == 0)
		ft_printf("rra\n");
	else if (reverse_rotate == 1)
		ft_printf("rrb\n");
}

void	ft_rr_rotate(t_cont **stack_a, t_cont **stack_b)
{
	ft_reverse_rotate(stack_a, 2);
	ft_reverse_rotate(stack_b, 2);
	ft_printf("rrr\n");
}
