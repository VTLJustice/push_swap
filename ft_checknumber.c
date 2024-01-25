/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:42 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 15:35:16 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checknumber(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (argv[i] == '\0')
		return (0);
	while (argv[i] != '\0')
	{
		if ((argv[i] == '-'
				|| argv[i] == '+') && ft_isdigit(argv[i + 1]) && count == 0)
		{
			count = 1;
			i++;
		}
		else if (ft_isdigit(argv[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
