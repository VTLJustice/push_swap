/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:52 by rradules          #+#    #+#             */
/*   Updated: 2024/02/01 19:36:39 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end(t_cont *stack)
{
	t_cont	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	exit(0);
}

void	ft_check_duplicity(t_cont **stack)
{
	t_cont	*current;
	t_cont	*temp;

	temp = *stack;
	while (temp)
	{
		current = temp->next;
		while (current)
		{
			if (temp->content == current->content)
				ft_error(-1);
			current = current->next;
		}
		temp = temp->next;
	}
}

void	ft_numbers(char **splitted, t_cont **stack)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		ft_lst_addback(stack, ft_atol(splitted[i]));
		i++;
	}
}

void	ft_handlespaces(char *argv, t_cont **stack)
{
	char	**splitted;
	int		found;

	found = ft_checkspaces(argv);
	if (found == 1)
	{
		splitted = ft_split(argv, ' ');
		ft_numbers(splitted, stack);
	}
	else
		ft_error(-1);
}

void	ft_getlist(char **argv)
{
	int		i;
	t_cont	*stack_a;
	t_cont	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = ft_newnode(3);
	while (argv[i])
	{
		if ((ft_checknumber(argv[i])) == 0)
		{
			ft_handlespaces(argv[i], &stack_a);
			i++;
		}
		else if ((ft_checknumber(argv[i])) == 1)
		{
			ft_lst_addback(&stack_a, ft_atol(argv[i]));
			i++;
		}
		else
			ft_error(-1);
	}
	ft_check_duplicity(&stack_a);
	ft_lst_addback(&stack_b, 5);
	ft_lst_addback(&stack_b, 6);
	ft_lst_addback(&stack_b, 10);
	ft_printstacks(stack_a, stack_b);
	ft_rrotate(&stack_a, &stack_b);
	//ft_rotate(&stack_b, RB);
	//ft_rotate(&stack_a, RA);
	//ft_push(&stack_a, &stack_b, PA);
	//ft_push(&stack_b, &stack_a, PB);
	//ft_sswap(stack_a, stack_b);
	//ft_swap(stack_b, SB);
	//ft_swap(stack_a, SA);
	//ft_reverse_rotate(&stack_a, RRA);
	//ft_reverse_rotate(&stack_b, RRB);
	//ft_rr_rotate(&stack_a, &stack_b);
	ft_printstacks(stack_a, stack_b);
}
