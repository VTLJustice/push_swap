/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:27:06 by rradules          #+#    #+#             */
/*   Updated: 2024/03/14 18:23:46 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cont	*stack;

	stack = NULL;
	if (argc > 1)
		ft_getlist(argv, &stack);
	if (ft_check_order(stack) == 1)
		ft_start_alg(&stack);
	ft_end(&stack);
	return (0);
}
