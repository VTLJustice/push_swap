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
	t_cont	*temp;
	t_cont	*head;
	t_cont	*last;

	temp = (*stack);
	last = (*stack);
	head = (*stack)->next;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = last;
			last->next = NULL;
			break ;
		}
		else
			temp = temp->next;
	}
	(*stack) = head;
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
