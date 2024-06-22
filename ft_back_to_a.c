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

int	ft_pos(t_cont *stack, int num);
int	ft_half(t_cont *stack);

void	ft_to_a(t_cont **stack_a, t_cont **stack_b, int num)
{
	int	diff;
	int	cmp;
	int	pos;
	int	i;
	int	half;
	int	flag;
	t_cont	*temp;

	i = 1;
	pos = i;
	half = ft_half(*stack_a);
	temp = *stack_a;
	diff = temp->content - num;
	flag = 0;
	while (temp)
	{
		cmp = temp->content - num;
		if ((cmp > 0 || diff < 0) && (cmp < diff || flag == 0) && num < temp->content)
		{
			flag++;
			diff = cmp;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	if (pos >= half)
	{
		pos = 1 + ft_count_numbers(*stack_a) - pos;
		while (pos-- > 0)
			ft_reverse_rotate(stack_a, RA);
	}
	else
	{
		while (pos-- > 1)
			ft_rotate(stack_a, RA);
	}
	ft_push(stack_a, stack_b, PA);
}

void	ft_m_go(t_cont **stack_a, t_cont **stack_b, int a)
{
	int	i;
	int	half;

	half = ft_half(*stack_a);
	i = ft_pos(*stack_a, a);
	if (i >= half)
	{
		i = 1 + ft_count_numbers(*stack_a) - i;
		while (i-- > 0)
			ft_reverse_rotate(stack_a, RA);
	}
	else
	{
		while (i-- > 1)
			ft_rotate(stack_a, RA);
	}
	ft_push(stack_a, stack_b, PA);
}

void	ft_sort_min(t_cont **stack_a)
{
	int	min;
	int	half;
	int	i;
	
	min = ft_min(*stack_a);
	i = ft_pos(*stack_a, min);
	half = ft_half(*stack_a);
	if (i > half)
	{
		i = 1 + ft_count_numbers(*stack_a) - i;
		while (i > 0)
		{
			ft_reverse_rotate(stack_a, RA);
			i--;
		}
	}
	else
	{
		while (i > 1)
		{
			ft_rotate(stack_a, RA);
			i--;
		}
	}
}

void	ft_move_to_a(t_cont **stack_a, t_cont **stack_b, int chosen, int *edges)
{
	int	a;

	a = (*stack_a)->content;
	if (chosen < edges[1] || chosen > edges[0])
	{
		a = edges[1];
		ft_m_go(stack_a, stack_b, a);
	}
	else
		ft_to_a(stack_a, stack_b, chosen);
}

void	ft_back_to_a(t_cont **stack_a, t_cont **stack_b)
{
	int	*edges;
	int	chosen;

	if (ft_check_order_b(*stack_a) == 1)
		ft_sort_three(stack_a);
	edges = malloc(sizeof(int) * 2);
	if (!edges)
		exit(-1);
	edges[0] = ft_max(*stack_a);
	edges[1] = (*stack_a)->content;
	while (ft_count_numbers(*stack_b) > 0)
	{
		chosen = (*stack_b)->content;
		ft_move_to_a(stack_a, stack_b, chosen, edges);
		edges[0] = ft_max(*stack_a);
		edges[1] = ft_min(*stack_a);
	}
	free(edges);
	if (ft_check_order(*stack_a) == 1)
		ft_sort_min(stack_a);
}
