/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:37:32 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 19:00:25 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_cont *stack_a, t_cont *stack_b)
{
	int	temp;
	t_cont	*temp_b;
	t_cont	*temp_a;

	temp = stack_b->content;
	temp_b = stack_b->next;
	free(stack_b);
	stack_b = temp_b;
	temp_a = ft_newnode(temp);
}
