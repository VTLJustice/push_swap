/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:42 by rradules          #+#    #+#             */
/*   Updated: 2023/11/27 19:41:09 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checknumber(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]) && count == 0)
			{
				count = 1;
				j++;
			}
			else if (ft_isdigit(argv[i][j]))
				j++;
			else if (argv[i][j] == ' ' && ft_isdigit(argv[i][j + 1]))
				j++;
			else
				return (-1);
		}
		count = 0;
		i++;
	}
	return (0);
}
