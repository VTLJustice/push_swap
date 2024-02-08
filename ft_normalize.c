#include "push_swap.h"

void	ft_normalize(t_cont **stack)
{
	int	max_number;
	int	min;
	int	current;
	int	next_min;
	t_cont	*get_min;

	max_number = 1;
	get_min = (*stack);
	while (get_min)
	{
		get_min = get_min->next;
		max_number++;
	}
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
			(*stack)->content = current;
			current++;
			if ((*stack)->next == NULL)
			{
				next_min++;
				(*stack) = get_min;
			}
			else
				(*stack) = (*stack)->next;
		}
		else
		{
			if ((*stack)->next == NULL)
			{
				next_min++;
				(*stack) = get_min;
			}
			else
				(*stack) = (*stack)->next;
		}
		if (current == max_number)
			break ;
		printf("%d\n", next_min);
	}
	(*stack) = get_min;
	ft_printstacks((*stack), (*stack));

}
