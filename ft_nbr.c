/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:27:35 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:54:57 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr(long int n)
{
	const char	*base;
	int			nbr_len;

	base = "0123456789";
	nbr_len = 0;
	if (n == LONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		return (20);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		nbr_len = nbr_len + ft_nbr(-n);
	}
	else if (n >= 10)
	{
		ft_nbr(n / 10);
		ft_nbr(n % 10);
	}
	else
		write(1, &base[n], 1);
	nbr_len = nbr_len + ft_nbrlen(n);
	return (nbr_len);
}
