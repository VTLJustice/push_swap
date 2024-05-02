/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:57:47 by rradules          #+#    #+#             */
/*   Updated: 2024/05/02 13:12:36 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos(t_cont *stack, int min);

void	ft_one_two_three(t_cont **stack_a, t_cont **stack_b, int pos_min)
{
	if (pos_min == 1)
		ft_push(stack_b, stack_a, PB);
	else if (pos_min == 2)
	{
		ft_swap((*stack_a), SA);
		ft_push(stack_b, stack_a, PB);
	}
	else
	{
		ft_rotate(stack_a, RRA);
		ft_rotate(stack_a, RRA);
		ft_push(stack_b, stack_a, PB);
	}
}

void	ft_four_five(t_cont **stack_a, t_cont **stack_b, int pos_min)
{
	if (pos_min == 4)
	{
		ft_reverse_rotate(stack_a, RA);
		ft_reverse_rotate(stack_a, RA);
		ft_push(stack_b, stack_a, PB);
	}
	else
	{
		ft_reverse_rotate(stack_a, RA);
		ft_push(stack_b, stack_a, PB);
	}
}

void	ft_sort_five(t_cont **stack_a, t_cont **stack_b)
{
	int	min;
	int	pos_min;

	min = ft_min(*stack_a);
	pos_min = ft_min_pos(*stack_a, min);
	if (pos_min < 4)
		ft_one_two_three(stack_a, stack_b, pos_min);
	else
		ft_four_five(stack_a, stack_b, pos_min);
	ft_sort_four(stack_a, stack_b);
	ft_push(stack_a, stack_b, PA);
}
