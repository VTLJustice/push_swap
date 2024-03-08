/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:50:38 by rradules          #+#    #+#             */
/*   Updated: 2024/03/06 18:27:57 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_cont *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	ft_min(t_cont *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_sorting_order(t_cont *stack)
{
	int	min;
	int	max;

	min = ft_min(stack);
	max = ft_max(stack);
	if (stack->content == min)
		return (1);
	else if (stack->content != min && stack->content != max)
	{
		if (stack->next->content == min)
			return (2);
		else
			return (3);
	}
	else if (stack->content == max)
	{
		if (stack->next->content == min)
			return (4);
		else
			return (5);
	}
	return (0);
}

void	ft_sort_three(t_cont **stack)
{
	if (ft_sorting_order(*stack) == 1)
	{
		ft_swap(*stack, SA);
		ft_rotate(stack, RA);
	}
	else if (ft_sorting_order(*stack) == 2)
		ft_swap(*stack, SA);
	else if (ft_sorting_order(*stack) == 3)
		ft_reverse_rotate(stack, RRA);
	else if (ft_sorting_order(*stack) == 4)
		ft_rotate(stack, RA);
	else if (ft_sorting_order(*stack) == 5)
	{
		ft_swap(*stack, SA);
		ft_reverse_rotate(stack, RRA);
	}
}
