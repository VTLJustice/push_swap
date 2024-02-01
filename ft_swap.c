/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:46:04 by rradules          #+#    #+#             */
/*   Updated: 2024/02/01 16:45:10 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_cont *stack, int swap)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (swap == 0)
		ft_printf("sa\n");
	else if (swap == 1)
		ft_printf("sb\n");
}

void	ft_sswap(t_cont	*stack_a, t_cont *stack_b)
{
	ft_swap(stack_a, 2);
	ft_swap(stack_b, 2);
	ft_printf("ss\n");
}
