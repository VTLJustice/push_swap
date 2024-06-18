/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:51:16 by rradules          #+#    #+#             */
/*   Updated: 2024/06/18 11:51:43 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_back(t_cont **stack_a, t_cont **stack_b, int pos)
{
	int	last_a;
	t_cont	*temp_a;
	int	i;

	i = 1;
	temp_a = (*stack_a);
	last_a = 1;
	while (temp_a->next != NULL)
	{
		temp_a = temp_a->next;
		last_a++;
	}
	if (pos == 1)
		ft_push(stack_a, stack_b, PA);
	else if (pos == 2)
	{
		ft_rotate(stack_a, RA);
		ft_push(stack_a, stack_b, PA);
		ft_reverse_rotate(stack_a, RRA);
	}
	else if (pos == last_a)
	{
		ft_push(stack_a, stack_b, PA);
		ft_rotate(stack_a, RA);
	}
	else if (pos > 2 && pos != last_a)
	{
		while (i < pos)
		{
			ft_rotate(stack_a, RA);
			i++;
		}
		ft_push(stack_a, stack_b, PA);
		while (i > 1)
		{
			ft_reverse_rotate(stack_a, RRA);
			i--;
		}
	}
	ft_printstacks(*stack_a, *stack_b);
}

void	ft_back_to_a(t_cont **stack_a, t_cont **stack_b)
{
	t_cont	*temp_a;
	t_cont	*temp_b;
	int	pos;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	if (ft_count_numbers(*stack_a) < 4)
		ft_sort_three(stack_a);
	temp_a = (*stack_a);
	pos = 1;
	while (temp_b || (ft_check_order(*stack_a) == 1))
	{
		while (temp_a)
		{
			if (temp_b->content - temp_a->content == -1)
			{
				ft_put_back(stack_a, stack_b, pos);
				break ;
			}
			else if (pos == ft_count_numbers(*stack_a))
			{
				ft_put_back(stack_a, stack_b, pos);
				break ;
			}
			pos++;
			temp_a = temp_a->next;
		}
		temp_a = (*stack_a);
		pos = 1;
		temp_b = (*stack_b);
	}
}
