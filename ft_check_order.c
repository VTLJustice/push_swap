/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:52:51 by rradules          #+#    #+#             */
/*   Updated: 2024/03/05 13:25:37 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_cont *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			break ;
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}
