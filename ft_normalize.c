/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:37:08 by rradules          #+#    #+#             */
/*   Updated: 2024/03/05 13:25:26 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <strings.h>

int	ft_find_min(t_cont *stack, char *pos)
{
	int	i;
	int	min;

	i = 0;
	min = stack->content;
	while (stack)
	{
		if (pos[i] == '0')
		{
			min = stack->content;
			break ;
		}
		else
		{
			i++;
			stack = stack->next;
		}
	}
	return (min);
}

t_cont	*ft_get_min(t_cont *head, char *pos)
{
	int		i;
	int		pos_min;
	int		min;
	t_cont	*current_min;

	i = 0;
	pos_min = 0;
	min = ft_find_min(head, pos);
	while (head)
	{
		if (head->content <= min && pos[i] == '0')
		{
			current_min = head;
			min = head->content;
			pos_min = i;
		}
		i++;
		head = head->next;
	}
	pos[pos_min] = '1';
	return (current_min);
}

int	ft_count_numbers(t_cont *stack)
{
	int		list_size;

	list_size = 0;
	while (stack)
	{
		stack = stack->next;
		list_size++;
	}
	return (list_size);
}

void	ft_normalize(t_cont **stack)
{
	int		list_size;
	char	*pos;
	int		normalizer;
	t_cont	*head;
	t_cont	*min;

	normalizer = 1;
	head = (*stack);
	min = NULL;
	list_size = ft_count_numbers(*stack);
	pos = ft_calloc(sizeof(char), list_size);
	if (!pos)
	{
		free(pos);
		exit(-1);
	}
	while (normalizer < list_size + 1)
	{
		min = ft_get_min(head, pos);
		(*stack) = min;
		(*stack)->content = normalizer;
		normalizer++;
	}
	free(pos);
	(*stack) = head;
}
