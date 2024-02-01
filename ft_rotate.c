/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:07:27 by rradules          #+#    #+#             */
/*   Updated: 2024/01/31 19:36:46 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_cont **stack_a, int rr)
{
	t_cont	*tempnode;
	t_cont	*head;

	tempnode = (*stack_a);
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
	head->next = (*stack_a);
	(*stack_a) = head;
	if (rr == 0)
		printf("ra\n");
}

void	ft_rotate_b(t_cont **stack_b, int rr)
{
	t_cont	*tempnode;
	t_cont	*head;

	tempnode = (*stack_b);
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
	head->next = (*stack_b);
	(*stack_b) = head;
	if (rr == 0)
		printf("rb\n");
}

void	ft_rrotate(t_cont **stack_a, t_cont **stack_b)
{
	ft_rotate_a(stack_a, 1);
	ft_rotate_b(stack_b, 1);
	printf("rr\n");
}
