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
/*
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
}*/

void	ft_to_a(t_cont *stack_a, t_cont *stack_b, int num)
{
	int	diff;
	int	cmp;
	int	pos;
	int	i;
	int	half;

	i = 1;
	pos = i;
	diff = stack_a->content - num;
	half = ft_half(stack_a);
	while (stack_a->next != NULL)
	{
		i++;
		cmp = stack_a->next->content - num;
		if (cmp > 0 && cmp < diff)
			pos = i;
		stack_a = stack_a->next;
	}
	if (pos >= half)
	{
		pos = 1 + ft_count_numbers(stack_a) - pos;
		while (pos > 0)
		{
			ft_reverse_rotate(&stack_a, RA);
			pos--;
		}
	}
	else
	{
		while (pos > 1)
		{
			ft_rotate(&stack_a, RA);
			pos--;
		}
	}
	ft_push(&stack_a, &stack_b, PA);
}

void	ft_m_go(t_cont *stack_a, t_cont *stack_b, int a)
{
	int	i;
	int	half;

	half = ft_half(stack_a);
	i = ft_pos(stack_a, a);
	if (i >= half)
	{
		i = 1 + ft_count_numbers(stack_a) - i;
		while (i > 0)
		{
			ft_reverse_rotate(&stack_a, RA);
			i--;
		}
	}
	else
	{
		while (i > 1)
		{
			ft_rotate(&stack_a, RA);
			i--;
		}
	}
	ft_push(&stack_a, &stack_b, PA);
}

void	ft_sort_min(t_cont **stack_a)
{
	int	min;
	int	half;
	int	i;
	
	min = ft_min(*stack_a);
	i = ft_pos(*stack_a, min);
	half = ft_half(*stack_a);
	if (i >= half)
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
			ft_reverse_rotate(stack_a, RA);
			i--;
		}
	}
}

void	ft_move_to_a(t_cont *stack_a, t_cont *stack_b, int chosen, int *edges)
{
	int	a;

	a = stack_a->content;
	if (chosen > edges[1])
	{
		a = edges[0];
		ft_m_go(stack_a, stack_b, a);
	}
	else if (chosen > edges[0])
	{
		a = ft_max(stack_a);
		ft_m_go(stack_a, stack_b, a);
	}
	else
		ft_to_a(stack_a, stack_b, chosen);
}

void	ft_back_to_a(t_cont **stack_a, t_cont **stack_b)
{
	int	*edges;
	t_cont	*temp_a;
	t_cont	*temp_b;
	
	temp_b = (*stack_b);
	temp_a = (*stack_a);
	edges = malloc(sizeof(int) * 2);
	if (!edges)
		exit(-1);
	edges[0] = ft_max(*stack_a);
	edges[1] = (*stack_a)->content;
	ft_printf("aqui\n");
	ft_printstacks(*stack_a, *stack_b);
	while (ft_count_numbers(*stack_b) > 0)
	{
		ft_move_to_a(temp_a, temp_b, temp_b->content, edges);
		temp_b = temp_b->next;
		edges[0] = ft_max(*stack_a);
		edges[1] = ft_min(*stack_a);
	}
	if (ft_check_order(*stack_a) == 1)
		ft_sort_min(stack_a);
}
