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
/*
int	ft_find_pos_b(t_cont *stack_b, int num, int max, int min)
{
	int	i;
	int	pos;
	int	cmp;

	cmp = 0;
	i = 1;
	pos = i;
	if (num > max || num < min)
	{
		while (stack_b)
		{
			if (stack_b->content == max)
				break ;
			pos++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b)
		{
			cmp = num - stack_b->content;
			if ((cmp > 0) && (cmp == 1))
				pos = i;
			i++;
			stack_b = stack_b->next;
		}
	}
	return (pos);
}

int	ft_chosen(t_cont *stack_a, int pos)
{
	int	i;
	int	chosen;

	i = 1;
	while (i <= pos)
	{
		chosen = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	return (chosen);
}

int	ft_find_pos(t_cont *stack_b, int content)
{
	int	cmp;
	int	pos;
	int	i;

	i = 1;
	pos = i;
	cmp = content - stack_b->content;
	stack_b = stack_b->next;
	i++;
	while (stack_b)
	{
		cmp = content - stack_b->content;
		if ((cmp > 0) && (cmp == 1))
			pos = i;
		i++;
		stack_b = stack_b->next;
	}
	return(pos);
}

int	ft_max_or_min(t_cont *stack_b, int max)
{
	int		steps;
	t_cont	*temp;

	steps = 0;
	temp = stack_b;
	while (temp->next != NULL)
		temp = temp->next;
	if (stack_b->content == max)
		return (steps);
	else if (stack_b->next->content == max)
		return ((steps + 1));
	else if (temp->content == max)
		return ((steps + 1));
	else
	{
		while (stack_b->content != max)
		{
			steps += 1;
			stack_b = stack_b->next;
		}
	}
	return (steps);
}

int	ft_find_steps(t_cont *stack_a, t_cont *stack_b, int max, int min)
{
	int	movements;
	int	pos;
	int	cmp;
	int	best_move;
	int	chosen;

	pos = 1;
	cmp = stack_a->content;
	if (cmp > max)
		best_move = pos + ft_max_or_min(stack_b, max);
	else if (cmp < min)
		best_move = pos + ft_max_or_min(stack_b, max);
	else
		best_move = pos + ft_find_pos(stack_b, cmp);
	chosen = pos;
	stack_a = stack_a->next;
	while (stack_a)
	{
		cmp = stack_a->content;
		if (cmp > max)
			movements = pos + ft_max_or_min(stack_b, max);
		else if (cmp < min)
			movements = pos + ft_max_or_min(stack_b, max);
		else
			movements = pos + ft_find_pos(stack_b, cmp);
		if (best_move > movements)
		{
			best_move = movements;
			chosen = pos;
		}
		pos++;
		stack_a = stack_a->next;
	}
	return (chosen);
}

void	ft_do_steps(t_cont **stack_a, t_cont **stack_b, int chosen)
{
	int	pos_b;
	int	last_a;
	int	last_b;
	t_cont	*temp_a;
	t_cont	*temp_b;

	temp_a = (*stack_a);
	temp_b = (*stack_b);
	last_a = 1;
	last_b = 1;
	while (temp_a->next != NULL)
	{
		temp_a = temp_a->next;
		last_a++;
	}
	while (temp_b->next != NULL)
	{
		temp_b = temp_b->next;
		last_b++;
	}
	pos_b = ft_find_pos_b(*stack_b, ft_chosen((*stack_a), chosen), ft_max(*stack_b), ft_min(*stack_b));
	if (chosen == 1 && pos_b == 1)
		ft_push(stack_b, stack_a, PB);
	else if (chosen == 1 && pos_b == 2)
	{
		ft_swap(*stack_b, SB);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == 1 && pos_b == last_b)
	{
		ft_reverse_rotate(stack_b, RRB);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == 2 && pos_b == 1)
	{
		ft_swap(*stack_a, SA);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == 2 && pos_b == 2)
	{
		ft_sswap(*stack_a, *stack_b);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == 2 && pos_b == last_b)
	{
		ft_swap(*stack_a, SA);
		ft_reverse_rotate(stack_b, RRB);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == last_a && pos_b == 1)
	{
		ft_reverse_rotate(stack_a, RRA);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == last_a && pos_b == 2)
	{
		ft_reverse_rotate(stack_a, RRA);
		ft_swap(*stack_b, SB);
		ft_push(stack_b, stack_a, PB);
	}
	else if (chosen == last_a && pos_b == last_b)
	{
		ft_rr_rotate(stack_a, stack_b);
		ft_push(stack_b, stack_a, PB);
	}
	else
	{
		 while(pos_b > 1 && chosen > 1)
		 {
			 if (chosen > pos_b)
			 {
				 ft_rotate(stack_a, RA);
				 chosen--;
			 }
			 else if (chosen < pos_b)
			 {
				 ft_rotate(stack_b, RRB);
				 pos_b--;
			 }
			 else
			 {
				 ft_rrotate(stack_a, stack_b);
				 chosen--;
				 pos_b--;
			 }
		 }
		 ft_push(stack_b, stack_a, PB);
	}
	ft_printstacks(*stack_a, *stack_b);
}

void	ft_first_steps(t_cont **stack_a, t_cont **stack_b)
{
	int	min;
	int	max;
	int	chosen;

	max = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	if (ft_check_order(*stack_a) == 0)
	{
		ft_back_to_a(stack_a, stack_b);
		ft_end(stack_b);
		exit(1);
	}
	if (max < (*stack_a)->content)
		max = (*stack_a)->content;
	else
		min = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	if (ft_check_order(*stack_a) == 0)
	{
		ft_back_to_a(stack_a, stack_b);
		ft_end(stack_b);
		exit(1);
	}
	while (ft_count_numbers(*stack_a) > 3)
	{
		chosen = ft_find_steps(*stack_a, *stack_b, max, min);
		ft_do_steps(stack_a, stack_b, chosen);
		min = ft_min(*stack_b);
		max = ft_max(*stack_b);
	}
}
*/
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

	if (ft_count_numbers(stack) % 2 == 0)
		i = ft_count_numbers(stack) / 2;
	else
		i = ft_count_numbers(stack) / 2 + 1;
	return (i);
}

void	ft_do_steps(t_cont **stack_a, t_cont **stack_b, int *num, int *edges)
{
	int	half_a;
	int	half_b;
	int	pos_a;
	int	pos_b;

	pos_a = ft_pos(*stack_a, num[0]);
	if (num[0] > edges[0])
		pos_b = ft_pos(*stack_b, edges[0]);
	else if (num[0] < edges[1])
		pos_b = ft_pos(*stack_b, edges[0]);
	else
		pos_b = ft_pos(*stack_b, num[1]);
	half_a = ft_half(*stack_a);
	half_b = ft_half(*stack_b);
	if (pos_a >= half_a && pos_b >= half_b)
	{
		pos_a = 1 + ft_count_numbers(*stack_a) - pos_a;
		pos_b = 1 + ft_count_numbers(*stack_b) - pos_b;
		while (pos_a > 0 && pos_b > 0)
		{
			if (pos_a > pos_b)
			{
				ft_reverse_rotate(stack_a, RA);
				pos_a--;
			}
			else if (pos_a < pos_b)
			{
				ft_reverse_rotate(stack_b, RB);
				pos_b--;
			}
			else
			{
				ft_rr_rotate(stack_a, stack_b);
				pos_a--;
				pos_b--;
			}
		}
		ft_push(stack_b, stack_a, PB);
	}
	else if (pos_a <= half_a && pos_b <= half_b)
	{
		while (pos_a > 1 && pos_b > 1)
		{
			if (pos_a > pos_b)
			{
				ft_rotate(stack_a, RA);
				pos_a--;
			}
			else if (pos_a < pos_b)
			{
				ft_rotate(stack_b, RB);
				pos_a--;
			}
			else
			{
				ft_rrotate(stack_a, stack_b);
				pos_a--;
				pos_b--;
			}
		}
		ft_push(stack_b, stack_a, PB);
	}
	else if (pos_a >= half_a && pos_b <= half_b)
	{	
		pos_a = 1 + ft_count_numbers(*stack_a) - pos_a;
		while (pos_a > 0)
		{
			ft_reverse_rotate(stack_a, RRA);
			pos_a--;
		}
		while (pos_b > 1)
		{
			ft_rotate(stack_b, RB);
			pos_b--;
		}
		ft_push(stack_b, stack_a, PB);
	}
	else
	{
		pos_b = 1 + ft_count_numbers(*stack_b) - pos_b;
		while (pos_b > 0)
		{
			ft_reverse_rotate(stack_b, RRB);
			pos_b--;
		}
		while (pos_a > 1)
		{
			ft_rotate(stack_a, RA);
			pos_a--;
		}
		ft_push(stack_b, stack_a, PB);
	}
}

int	ft_count_steps(t_cont *stack_a, t_cont *stack_b, int a, int b)
{
	int	i;
	int	j;
	int	nums_a;
	int	nums_b;

	nums_a = ft_count_numbers(stack_a);
	nums_b = ft_count_numbers(stack_b);
	i = ft_pos(stack_a, a);
	j = ft_pos(stack_b, b);
	if (i >= ft_half(stack_a))
		i = nums_a - i;
	if (j >= ft_half(stack_b))
		j = nums_b - i;
	if (i == j)
		return (i);
	else if (i > j)
		return (i);
	else
		return (j);
}

int	*ft_find_steps(t_cont *stack_a, t_cont *stack_b, int *num, int *edge)
{
	int	diff;
	int	stp;
	int	cmp;
	int	*a;
	t_cont	*head;

	head = stack_b;
	diff = 0;
	edge = edge;
	num[0] = stack_a->content;
	num[1] = stack_b->content;
	a = malloc(sizeof(int) * 2);
	while (stack_a)
	{
		while (stack_b->next != NULL)
		{
			ft_printf("stack_a->content = %d\n", stack_a->content);
			if (stack_a->content > edge[0] || stack_a->content < edge[1])
			{
				a[0] = edge[0];
				break ;
			}
			diff = stack_a->content - stack_b->content;
			if (diff > (stack_a->content - stack_b->next->content) ||
					diff < 0)
				a[0] = stack_b->content;
			stack_b = stack_b->next;
		}
		stack_b = head;
		stp = ft_count_steps(stack_a, stack_b, stack_a->content, a[0]);
		ft_printf("stp = %d, stk_a = %d a[0] = %d\n", stp, stack_a->content, a[0]);
		if (stack_a->next != NULL)
			stack_a = stack_a->next;
		while (stack_b->next != NULL)
		{
			if (stack_a->content > edge[0] || stack_a->content < edge[1])
			{
				a[1] = edge[0];
				break ;
			}
			diff = stack_a->content - stack_b->content;
			if (diff > stack_a->content - stack_b->next->content ||
					diff < 0)
				a[1] = stack_b->content;
			stack_b = stack_b->next;
		}
		stack_b = head;
		cmp = ft_count_steps(stack_a, stack_b, stack_a->content, a[1]);
		ft_printf("cmp = %d, stk_a = %d a[1] = %d\n", cmp, stack_a->content, a[1]);
		if (stp > cmp)
		{
			num[0] = stack_a->content;
			num[1] = a[1];
		}
		stack_a = stack_a->next;
	}
	free(a);
	ft_printf("num_a = %d, num_b = %d\n", num[0], num[1]);
	return (num);
}

void	ft_first_steps(t_cont **stack_a, t_cont **stack_b)
{
	int	*chosen;
	int	*max_min;

	chosen = malloc(sizeof(int) * 2);
	if (!chosen)
		exit(-1);
	max_min = malloc(sizeof(int) * 2);
	if (!max_min)
		exit(-1);
	max_min[0] = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	if (max_min[0] < (*stack_a)->content)
		max_min[0] = (*stack_a)->content;
	else
		max_min[1] = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	ft_printstacks(*stack_a, *stack_b);
	while (ft_count_numbers(*stack_a) > 3)
	{
		chosen = ft_find_steps(*stack_a, *stack_b, chosen, max_min);
		ft_do_steps(stack_a, stack_b, chosen, max_min);
		max_min[0] = ft_max(*stack_b);
		max_min[1] = ft_min(*stack_b);
		ft_printstacks(*stack_a, *stack_b);
	}
	free(chosen);
	free(max_min);
}

void	ft_start_alg(t_cont **stack)
{
	t_cont	*stack_b;

	stack_b = NULL;
	ft_printstacks(*stack, stack_b);
	if (ft_count_numbers(*stack) < 4)
		ft_sort_three(stack);
	else if (ft_count_numbers(*stack) < 5)
		ft_sort_four(stack, &stack_b);
	else if (ft_count_numbers(*stack) < 6)
		ft_sort_five(stack, &stack_b);
	else
		ft_first_steps(stack, &stack_b);
	ft_back_to_a(stack, &stack_b);
	ft_end(&stack_b);
}
