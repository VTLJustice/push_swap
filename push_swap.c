/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:27:06 by rradules          #+#    #+#             */
/*   Updated: 2023/11/27 19:04:36 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = ft_checknumber(argv);
		j = ft_atol(argv[1]);
		if (i == 0)
			printf("%i\n", (ft_newlist(j))->content);
		else
			printf("Error\n");
	}
	return (0);
}
