/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:17 by rradules          #+#    #+#             */
/*   Updated: 2023/12/12 20:04:37 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_splitcheck(char *argv)
{
	int		i;
	char	**new;

	i = 0;
	while (argv[i] != '\0')
	{
		if ((ft_isdigit(argv[i])) == 1)
			i++;
		else if (argv[i] == ' ' && i > 0)
			i++;
		else if (argv[i] == '-')
		{
			if (i == 0)
				i++;
			else if (argv[i - 1] == ' ' && (ft_isdigit(argv[i + 1])))
				i++;
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	new = ft_split(argv, ' ');
	return (new);
}
