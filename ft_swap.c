/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:46:04 by rradules          #+#    #+#             */
/*   Updated: 2024/01/31 16:50:24 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_cont *stack, int ss)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (ss == 0)
		ft_printf("sa\n");
}

void	ft_swap_b(t_cont *stack, int ss)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (ss == 0)
		ft_printf("sb\n");
}

void	ft_sswap(t_cont	*stack_a, t_cont *stack_b)
{
	ft_swap_a(stack_a, 1);
	ft_swap_b(stack_b, 1);
	ft_printf("ss\n");
}
