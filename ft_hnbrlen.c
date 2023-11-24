/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hnbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <rradules@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:02:01 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:55:50 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_hnbrlen(unsigned long int n, char format)
{
	size_t	i;

	if (format == 'x' || format == 'X')
		n = (unsigned int) n;
	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
