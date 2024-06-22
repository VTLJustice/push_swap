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

void	ft_sort_three(t_cont **stack)
{
	int	max;

	max = ft_max(*stack);
	if ((*stack)->content == max)
		ft_rotate(stack, RA);
	else if ((*stack)->next->content == max)
		ft_reverse_rotate(stack, RRA);
	if ((*stack)->content > (*stack)->next->content)
		ft_swap(*stack, RA);
}
