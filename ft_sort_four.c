/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:43:39 by rradules          #+#    #+#             */
/*   Updated: 2024/05/15 15:20:16 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_half(t_cont **stack_a, t_cont **stack_b, int pos, int p)
{
	if (pos == 1)
	{
		p = 1;
		ft_push(stack_b, stack_a, PB);
	}
	else if (pos == 2)
	{
		ft_swap((*stack_a), SA);
		if (ft_check_order(*stack_a) == 1)
		{
			ft_push(stack_b, stack_a, PB);
			p = 1;
		}
	}
	return (p);
}

int	ft_sec_half(t_cont **stack_a, t_cont **stack_b, int pos, int p)
{
	if (pos == 3)
	{
		ft_reverse_rotate(stack_a, RRA);
		ft_reverse_rotate(stack_a, RRA);
		if (ft_check_order(*stack_a) == 1)
		{
			ft_push(stack_b, stack_a, PB);
			p = 1;
		}
	}
	else
	{
		ft_reverse_rotate(stack_a, RRA);
		if (ft_check_order(*stack_a) == 1)
		{
			ft_push(stack_b, stack_a, PB);
			p = 1;
		}
	}
	return (p);
}

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
	int	pushed;

	pushed = 0;
	min = ft_min(*stack_a);
	pos_min = ft_min_pos(*stack_a, min);
	if (pos_min == 1 || pos_min == 2)
		pushed = ft_first_half(stack_a, stack_b, pos_min, 0);
	else
		pushed = ft_sec_half(stack_a, stack_b, pos_min, 0);
	if (ft_check_order(*stack_a) == 1)
		ft_sort_three(stack_a);
	if (pushed == 1)
		ft_push(stack_a, stack_b, PA);
}
