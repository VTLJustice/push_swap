/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <rradules@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:42:13 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 18:55:10 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_hex(va_arg(args, unsigned long int), format));
	else if (format == 'd' || format == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg(args, unsigned long int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			length = length + check_format(args, format[i + 1]);
			i++;
		}
		else
			length = length + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
