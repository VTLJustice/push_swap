/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:27:06 by rradules          #+#    #+#             */
/*   Updated: 2024/03/06 16:13:34 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cont	*stack;

	stack = NULL;
	if (argc > 1)
		ft_getlist(argv, &stack);
	else
		ft_error();
	if (ft_check_order(stack))
		ft_start_alg(&stack);
	else
		ft_error();
	ft_end(&stack);
	return (0);
}
