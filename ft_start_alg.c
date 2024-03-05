/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:04 by rradules          #+#    #+#             */
/*   Updated: 2024/03/05 15:31:30 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_alg(t_cont **stack)
{
	t_cont	*stack_b;
	t_cont	*last;

	stack_b = NULL;
	last = ft_lstlast(*stack);
	ft_printstacks(*stack, stack_b);
	while (ft_check_order(*stack) == 1)
	{
		if (((*stack)->content < (*stack)->next->content) && ((*stack)->content < last->content))
			ft_push(&stack_b, stack, PB);
		if (((*stack)->content < (*stack)->next->content) && ((*stack)->content > last->content))
			ft_reverse_rotate(stack, RRA);
		else
			ft_swap(*stack, SA);
	}
	ft_printstacks(*stack, stack_b);
}
