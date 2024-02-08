/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:37:08 by rradules          #+#    #+#             */
/*   Updated: 2024/02/08 18:20:19 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <strings.h>

void	ft_normalize(t_cont **stack)
{
	int		max_number;
	int		min;
	int		current;
	int		next_min;
	char	*pos;
	int		i;
	t_cont	*get_min;

	i = 0;
	max_number = 1;
	get_min = (*stack);
	while (get_min)
	{
		get_min = get_min->next;
		max_number++;
	}
	pos = malloc(sizeof(char) * (max_number - 1));
	if (!pos)
		free(pos);
	pos[max_number] = '\0';
	memset(pos, '0', max_number - 1);
	current = (*stack)->content;
	get_min = (*stack);
	while (get_min)
	{
		if (get_min->content < current)
			current = get_min->content;
		get_min = get_min->next;
	}
	min = current;
	get_min = (*stack);
	current = 1;
	ft_printstacks((*stack), (*stack));
	next_min = min;
	while (*stack)
	{
		if ((*stack)->content == next_min)
		{
			if (pos[i] == '0')
			{
				(*stack)->content = current;
				current++;
				pos[i] = '1';
				i++;
				printf("Posiciones %s\n", pos);
			}
			if ((*stack)->next == NULL)
			{
				(*stack) = get_min;
				next_min++;
				i = 0;
			}
			else
			{
				(*stack) = (*stack)->next;
				i++;
			}
		}
		else
		{
			if ((*stack)->next == NULL)
			{
				(*stack) = get_min;
				next_min++;
				i = 0;
			}
			else
			{
				(*stack) = (*stack)->next;
				i++;
			}
		}
		if (current == max_number)
			break ;
		//printf("%d\n", next_min);
	}
	(*stack) = get_min;
	ft_printstacks((*stack), (*stack));

}
