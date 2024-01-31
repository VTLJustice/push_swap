/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:07:27 by rradules          #+#    #+#             */
/*   Updated: 2024/01/31 19:36:46 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_cont **stack_a)
{
	t_cont	*head_a;
	t_cont	*tempnode;

	head_a = *stack_a;
	free(*stack_a);
	stack_a = stack_a->next;
	while ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	tempnode = *stack_a;
	printf("Valor del tempnode: %d\n", tempnode->content);
	printf("Valor del head_a: %d\n", head_a->content);
	(*stack_a)->next = head_a;

}
