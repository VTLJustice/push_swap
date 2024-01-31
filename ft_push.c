/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:37:32 by rradules          #+#    #+#             */
/*   Updated: 2024/01/31 18:40:59 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_cont **stack_a, t_cont **stack_b)
{
	int		newnode;
	t_cont	*head_b;
	t_cont	*head_a;

	newnode = (*stack_b)->content;
	head_b = (*stack_b)->next;
	free(*stack_b);
	*stack_b = head_b;
	head_a = ft_newnode(newnode);
	head_a->next = *stack_a;
	*stack_a = head_a;
	printf("pa\n");
}

void	ft_push_b(t_cont **stack_a, t_cont **stack_b)
{
	int		newnode;
	t_cont	*head_b;
	t_cont	*head_a;

	newnode = (*stack_a)->content;
	head_a = (*stack_a)->next;
	free(*stack_a);
	*stack_a = head_a;
	head_b = ft_newnode(newnode);
	head_b->next = *stack_b;
	*stack_b = head_b;
	printf("pb\n");
}
