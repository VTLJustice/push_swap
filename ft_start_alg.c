/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:04 by rradules          #+#    #+#             */
/*   Updated: 2024/03/06 18:23:52 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_cont **stack)
{
	if ((*stack)->content == 0)
	{
		ft_swap(*stack, SA);
		ft_rotate(stack, RA);
	}
	else if ((*stack)->content == 1)
	{
		if ((*stack)->next->content == 0)
			ft_swap(*stack, SA);
		else
			ft_reverse_rotate(stack, RRA);
	}
	else if ((*stack)->content == 2)
	{
		if ((*stack)->next->content == 0)
			ft_rotate(stack, RA);
		else
		{
			ft_swap(*stack, SA);
			ft_reverse_rotate(stack, RRA);
		}
	}
}

void	ft_start_alg(t_cont **stack)
{
	t_cont	*stack_b;
	t_cont	*last;

	stack_b = NULL;
	last = ft_lstlast(*stack);
	ft_printstacks(*stack, stack_b);
	ft_check_sort(stack);
	ft_printstacks(*stack, stack_b);
}
