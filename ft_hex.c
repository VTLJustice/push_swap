/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <rradules@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:11:04 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:54:38 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hex(unsigned long int n, char format)
{
	char				*base;
	unsigned int		nbr_len;

	base = "0123456789abcdef";
	nbr_len = 0;
	if (format == 'p')
	{
		write(1, "0x", 2);
		nbr_len += 2;
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	ft_writenum(n, base, format);
	nbr_len = nbr_len + ft_hnbrlen(n, format);
	return (nbr_len);
}
