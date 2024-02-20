/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:37:08 by rradules          #+#    #+#             */
/*   Updated: 2024/02/20 18:41:39 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <strings.h>

void	ft_if_min(t_cont **stack, int normalizer, char *pos, int i)
{
	(*stack)->content = normalizer;
	pos[i] = '1';
}

int	ft_count_numbers(t_cont **stack)
{
	int		max_number;
	t_cont	*get_max;

	max_number = 1;
	get_max = (*stack);
	while (get_max)
	{
		get_max = get_max->next;
		max_number++;
	}
	return (max_number);
}

void	stk(t_cont **stack, int min, int normalizer, char *pos)
{
	t_cont	*head;
	int		i;

	i = 0;
	head = (*stack);
	while (ft_check_number(pos) == 0)
	{
		if ((*stack)->content == min && pos[i] == '0')
		{
			ft_if_min(stack, normalizer, pos, i);
			normalizer++;
		}
		else if ((*stack)->next == NULL)
		{
			(*stack) = head;
			min++;
			i = 0;
		}
		else
		{
			(*stack) = (*stack)->next;
			i++;
		}
	}
	(*stack) = head;
}

void	ft_normalize(t_cont **stack)
{
	int		max_number;
	int		min;
	char	*pos;
	int		normalizer;
	t_cont	*get_min;

	normalizer = 1;
	max_number = ft_count_numbers(stack);
	pos = calloc(sizeof(int), (max_number - 1));
	if (!pos)
	{
		free(pos);
		exit(1);
	}
	ft_memset(pos, '0', max_number - 1);
	min = (*stack)->content;
	get_min = (*stack);
	while (get_min)
	{
		if (get_min->content < min)
			min = get_min->content;
		get_min = get_min->next;
	}
	stk(stack, min, normalizer, pos);
}
