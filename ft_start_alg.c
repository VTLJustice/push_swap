/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:21:04 by rradules          #+#    #+#             */
/*   Updated: 2024/05/28 18:23:43 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos(t_cont *stack, int num)
{
	int	i;

	i = 1;
	while (stack->content != num)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_half(t_cont *stack)
{
	int	i;

	i = ft_count_numbers(stack) / 2 + 1;
	if (ft_count_numbers(stack) == 2)
		i = 1;
	return (i);
}

int	ft_n_pos(t_cont *stack_b, int num)
{
	int	diff;
	int	cmp;
	int	pos;
	int	i;
	int	flag;
	t_cont	*temp;

	i = 1;
	pos = i;
	temp = stack_b;
	diff = num - temp->content;
	flag = 0;
	while (temp)
	{
		cmp = num - temp->content;
		if ((cmp > 0 || diff < 0) && (cmp < diff || flag == 0) && num > temp->content)
		{
			flag++;
			diff = cmp;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (pos);
}

void	ft_do_steps(t_cont **stack_a, t_cont **stack_b, int *best)
{
	int	half_a;
	int	half_b;

	half_a = ft_half(*stack_a);
	half_b = ft_half(*stack_b);
	if (best[0] == 1 && best[1] == ft_count_numbers(*stack_b))
		ft_reverse_rotate(stack_b, RB);
	else if (best[0] > half_a && best[1] > half_b)
	{
		best[0] = (ft_count_numbers(*stack_a) - best[0]) + 2;
		best[1] = (ft_count_numbers(*stack_b) - best[1]) + 1;
		while (best[0]-- > 0 || best[1]-- > 0)
		{
			if (best[0] > 0)
				ft_reverse_rotate(stack_a, RA);
			if (best[1] > 0)
				ft_reverse_rotate(stack_b, RB);
		}
	}
	else if (best[0] > half_a && best[1] <= half_b)
	{
		best[0] = (ft_count_numbers(*stack_a) - best[0]) + 2;
		while (best[0]-- > 0 || best[1]-- > 1)
		{
			if (best[0] > 0)
				ft_reverse_rotate(stack_a, RA);
			if (best[1] > 1)
				ft_rotate(stack_b, RB);
		}
	}
	else if (best[0] <= half_a && best[1] > half_b)
	{
		best[1] = (ft_count_numbers(*stack_b) - best[1]) + 1;
		while (best[0]-- > 1 || best[1]-- > 0)
		{
			if (best[0] > 1)
				ft_rotate(stack_a, RA);
			if (best[1] > 0)
				ft_reverse_rotate(stack_b, RB);
		}
	}
	else
	{
		while (best[0]-- > 1 || best[1]-- > 0)
		{
			if (best[0] > 1)
				ft_rotate(stack_a, RA);
			if (best[1] > 0)
				ft_rotate(stack_b, RB);
		}
	}
	ft_push(stack_b, stack_a, PB);
}

int	*ft_get_pos(t_cont *stack_a, t_cont *stack_b, int *chosen, int *edge)
{
	if (chosen[0] > edge[0] || chosen[0] < edge[1])
	{
		chosen[0] = ft_pos(stack_a, chosen[0]);
		chosen[1] = ft_pos(stack_b, edge[0]);
		return (chosen);
	}
	else
	{
		chosen[1] = ft_n_pos(stack_b, chosen[0]);
		chosen[0] = ft_pos(stack_a, chosen[0]);
		return (chosen);
	}
}

int	ft_count_steps(t_cont *stack_a, t_cont *stack_b, int *chosen)
{
	int	a;
	int	b;

	a = chosen[0];
	b = chosen[1];
	if (a == 1 && b == ft_count_numbers(stack_b))
		return (2);
	if (a > ft_half(stack_a))
		a = (ft_count_numbers(stack_a) - a) + 2;
	if (b > ft_half(stack_b))
		b = (ft_count_numbers(stack_b) - b) + 1;
	if (a == b)
		return (a);
	else if (a > b)
		return (a);
	else
		return (b);
}

int	*ft_find_pos(t_cont *stack_a, t_cont *stack_b, int *chosen, int *edge)
{
	int	*num;
	int	s_chosen;
	int	s_num;
	int	s_best;
	int	*best;
	t_cont	*temp;

	num = malloc(sizeof(int) * 2);
	best = malloc(sizeof(int) * 2);
	if (!num || !best)
		exit(-1);
	temp = stack_a;
	best[0] = temp->content;
	best = ft_get_pos(stack_a, stack_b, best, edge);
	s_best = ft_count_steps(stack_a, stack_b, best);
	while (temp->next != NULL)
	{
		chosen[0] = temp->content;
		chosen = ft_get_pos(stack_a, stack_b, chosen, edge);
		s_chosen = ft_count_steps(stack_a, stack_b, chosen);
		if (temp->next == NULL)
			break ;
		num[0] = temp->next->content;
		num = ft_get_pos(stack_a, stack_b, num, edge);
		s_num = ft_count_steps(stack_a, stack_b, num);
		if (s_best > 1 && (s_best > s_chosen && s_best > s_num))
		{
			if (s_chosen > s_num)
				best = num;
			else
				best = chosen;
		}
		temp = temp->next;
	}
	return (best);
}

void	ft_first_steps(t_cont **stack_a, t_cont **stack_b)
{
	int	*chosen;
	int	*edges;

	chosen = malloc(sizeof(int) * 2);
	edges = malloc(sizeof(int) * 2);
	if (!edges || !chosen)
		exit(-1);
	ft_push(stack_b, stack_a, PB);
	ft_push(stack_b, stack_a, PB);
	while (ft_count_numbers(*stack_a) > 3)
	{
		edges[0] = ft_max(*stack_b);
		edges[1] = ft_min(*stack_b);
		chosen = ft_find_pos(*stack_a, *stack_b, chosen, edges);
		ft_do_steps(stack_a, stack_b, chosen);
	}
	free(chosen);
	free(edges);
}

void	ft_start_alg(t_cont **stack)
{
	t_cont	*stack_b;

	stack_b = NULL;
	//ft_printstacks(*stack, stack_b);
	if (ft_count_numbers(*stack) < 4)
		ft_sort_three(stack);
	else if (ft_count_numbers(*stack) < 5)
		ft_sort_four(stack, &stack_b);
	else if (ft_count_numbers(*stack) < 6)
		ft_sort_five(stack, &stack_b);
	else
	{
		ft_first_steps(stack, &stack_b);
		ft_back_to_a(stack, &stack_b);
	}
	//ft_printstacks(*stack, stack_b);
	ft_end(&stack_b);
}
