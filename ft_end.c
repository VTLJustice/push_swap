/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:25:33 by rradules          #+#    #+#             */
/*   Updated: 2024/03/06 16:02:57 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end(t_cont **stack)
{
	t_cont	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		(*stack) = temp;
	}
}
