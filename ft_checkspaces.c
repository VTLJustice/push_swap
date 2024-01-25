/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:15:38 by rradules          #+#    #+#             */
/*   Updated: 2024/01/25 15:34:52 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkspaces(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
		return (0);
	while (argv[i] != '\0')
	{
		if ((ft_isdigit(argv[i])) == 1)
			i++;
		else if ((ft_isdigit(argv[i])) == 0)
		{
			if ((argv[i] == '-' || argv[i] == '+') && ft_isdigit(argv[i + 1]))
				i++;
			else if (argv[i] == ' ' && i != 0)
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
