/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:04:53 by rradules          #+#    #+#             */
/*   Updated: 2023/11/24 19:23:31 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

/* push_swap struct */

typedef struct s_container
{
	int					*content;
	struct s_container	*next;
}						t_cont;

/* push_swap functions */
t_cont	*ft_newlist(int *content);

/* ft_printf functions */
int		ft_printf(char const *format, ...);
int		ft_hex(unsigned long int n, char format);
int		ft_putnbr(unsigned long int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_nbr(long int n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_hnbrlen(unsigned long int n, char format);
size_t	ft_nbrlen(long int n);
int		ft_writenum(unsigned long int n, char *base, char format);

#endif
