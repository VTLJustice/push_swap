/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:22:13 by rradules          #+#    #+#             */
/*   Updated: 2024/02/20 15:22:30 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *str, size_t c, size_t n)
{
	size_t			i;
	unsigned char	*temp_str;

	i = 0;
	temp_str = (unsigned char *)str;
	while (i < n)
	{
		*temp_str = (unsigned char)c;
		i++;
		temp_str++;
	}
	return (str);
}
