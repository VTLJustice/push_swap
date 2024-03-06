/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:52 by rradules          #+#    #+#             */
/*   Updated: 2024/03/06 16:00:53 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_error();
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
		ft_error();
}

void	ft_getlist(char **argv, t_cont **stack)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if ((ft_checknumber(argv[i])) == 0)
		{
			ft_handlespaces(argv[i], stack);
			i++;
		}
		else if ((ft_checknumber(argv[i])) == 1)
		{
			ft_lst_addback(stack, ft_atol(argv[i]));
			i++;
		}
		else
			ft_error();
	}
	ft_check_duplicity(stack);
	ft_normalize(stack);
}
