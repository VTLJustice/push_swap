/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:46:00 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:55:39 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_writenum(unsigned long int n, char *base, char format)
{
	if (format == 'x' || format == 'X')
		n = (unsigned int) n;
	if (n >= 16)
	{
		ft_writenum(n / 16, base, format);
		ft_writenum(n % 16, base, format);
	}
	else
		write(1, &base[n], 1);
	return (0);
}
