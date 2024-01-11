/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:22:18 by rradules          #+#    #+#             */
/*   Updated: 2024/01/10 17:31:35 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i, t_cont *stack)
{
	if (i == 0)
		ft_printf("Error\n");
	else
	{
		ft_printf("Error\n");
		free(stack);
	}
	exit (-1);
}
