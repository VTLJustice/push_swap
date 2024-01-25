/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:46:04 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 18:35:57 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_cont *stack)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_cont *stack)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	ft_printf("sb\n");
}

void	ft_sswap(t_cont	*stack_a, t_cont *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	ft_printf("ss\n");
}
