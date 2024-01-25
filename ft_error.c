/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:22:18 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:14 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i)
{
	if (i == -1)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	if (i == 1)
	{
		ft_printf("Error\n");
		exit(-1);
	}
}
