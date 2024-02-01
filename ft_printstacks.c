/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:55:21 by rradules          #+#    #+#             */
/*   Updated: 2024/02/01 18:08:20 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstacks(t_cont *stack_a, t_cont *stack_b)
{
	printf("Stack_a         Stack_b\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			printf("   %d", stack_a->content);
		else
			printf("    ");
		printf("\t\t");
		if (stack_b)
			printf("   %d", stack_b->content);
		else
			printf(" ");
		printf("\n");
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}
