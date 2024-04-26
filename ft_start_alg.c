/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:04 by rradules          #+#    #+#             */
/*   Updated: 2024/04/18 17:46:44 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_find_steps(t_cont *stack_a, t_cont *stack_b)
{

}

int	ft_calc_steps(t_cont *stack_a, t_cont *stack_b)
{

}

void	ft_first_steps(t_cont **stack_a, t_cont **stack_b)
{

}
*/
void	ft_start_alg(t_cont **stack)
{
	t_cont	*stack_b;

	stack_b = NULL;
	ft_printstacks(*stack, stack_b);
	if (ft_count_numbers(*stack) < 4)
		ft_sort_three(stack);
	else
	{
		//ft_first_steps(stack, &stack_b);
	}
	ft_printstacks(*stack, stack_b);
	ft_end(&stack_b);
}
