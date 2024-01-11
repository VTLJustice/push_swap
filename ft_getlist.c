/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:43:52 by rradules          #+#    #+#             */
/*   Updated: 2024/01/11 18:29:40 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_numbers(char **argv, t_cont *list)
{

}
*/
void	ft_getlist(char **argv)
{
	int		i;
	int		a;
	int		check;
	char	**splitted;
	t_cont	*stack_a;

	i = 1;
	a = 0;
	stack_a = ft_newlist(100);
	while (argv[i] != '\0')
	{
		if ((ft_checkspaces(argv[i])) == 1)
		{
			splitted = ft_splitcheck(argv[i]);
			ft_printf("%d\n", 1);
		//	ft_numbers(splitted, stack_a);
			i++;
		}
		else
		{
			check = ft_checknumber(argv[i]);
			if (check == 0)
			{
				stack_a->content = ft_atol(argv[i]);
				printf("%d\n", stack_a->content);
			}
			else
				ft_error(0, stack_a);
		}
		i++;
	}
	while (stack_a)
	{
		printf("%d,", stack_a->content);
	}
}
