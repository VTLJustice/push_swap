/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:09:50 by rradules          #+#    #+#             */
/*   Updated: 2024/02/01 19:36:37 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_cont **stack, int rotate)
{
	t_cont	*last;
	t_cont	*newhead;

	last = (*stack);
	last->next = NULL;
	(*stack) = (*stack)->next;
	newhead = (*stack);
	while ((*stack))
		(*stack) = (*stack)->next;
	(*stack)->next = last;
	(*stack) = newhead;
	//last->next = NULL;
	if (rotate == 0)
		ft_printf("ra\n");
	else if (rotate == 1)
		ft_printf("rb\n");
}

void	ft_rrotate(t_cont **stack_a, t_cont **stack_b)
{
	ft_rotate(stack_a, 2);
	ft_rotate(stack_b, 2);
	ft_printf("rr\n");
}
