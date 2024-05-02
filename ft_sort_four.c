/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:43:39 by rradules          #+#    #+#             */
/*   Updated: 2024/05/02 12:55:09 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos(t_cont *stack, int min)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		if (stack->content == min)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

void	ft_sort_four(t_cont **stack_a, t_cont **stack_b)
{
	int	min;
	int	pos_min;

	min = ft_min(*stack_a);
	pos_min = ft_min_pos(*stack_a, min);
	if (pos_min == 1)
		ft_push(stack_b, stack_a, PB);
	else if (pos_min == 2)
	{
		ft_swap((*stack_a), SA);
		ft_push(stack_b, stack_a, PB);
	}
	else if (pos_min == 3)
	{
		ft_reverse_rotate(stack_a, RRA);
		ft_reverse_rotate(stack_a, RRA);
		ft_push(stack_b, stack_a, PB);
	}
	else
	{
		ft_reverse_rotate(stack_a, RRA);
		ft_push(stack_b, stack_a, PB);
	}
	ft_sort_three(stack_a);
	ft_push(stack_a, stack_b, PA);
}
