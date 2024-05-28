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

int	ft_max(t_cont *stack);

int	ft_find_pos(t_cont *stack_b, int content)
{
	int	diff;
	int	cmp;
	int	pos;

	pos = 1;
	cmp = content - stack_b->content;
	diff = cmp;
	stack_b = stack_b->next;
	while (stack_b)
	{
		cmp = content - stack_b->content;
		if ((cmp > 0) && (cmp < diff))
		{
			diff = cmp;
			pos++;
		}
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
	int	best_move;
	int	cmp;
	int	chosen;

	pos = 1;
	cmp = stack_a->content;
	best_move = pos + ft_max_or_min(stack_b, max);
	ft_printf("Best move = %d\n", best_move);
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
	ft_printf("Chosen pos = %d\n", chosen);
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
	while (temp_a->next != NULL)
		temp_a = temp_a->next;
	last_a = temp_a->content;
	while (temp_b->next != NULL)
		temp_b = temp_b->next;
	last_b = temp_b->content;
	pos_b = ft_find_pos(*stack_b, chosen);
	if (chosen == pos_b)
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
}

void	ft_first_steps(t_cont **stack_a, t_cont **stack_b)
{
	int	min;
	int	max;
	int	pos;

	max = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	if (max < (*stack_a)->content)
		max = (*stack_a)->content;
	else
		min = (*stack_a)->content;
	ft_push(stack_b, stack_a, PB);
	while (ft_count_numbers(*stack_a) > 3)
	{
		pos = ft_find_steps(*stack_a, *stack_b, max, min);
		ft_do_steps(stack_a, stack_b, pos);
		min = ft_min(*stack_b);
		max = ft_max(*stack_b);
	}
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
	ft_printstacks(*stack, stack_b);
	ft_end(&stack_b);
}
