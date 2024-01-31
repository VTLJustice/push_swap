/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:04:53 by rradules          #+#    #+#             */
/*   Updated: 2024/01/31 19:11:26 by rradules         ###   ########.fr       */
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
	int					content;
	struct s_container	*next;
}						t_cont;

/* push_swap functions */
t_cont	*ft_newnode(int content);
int		ft_atol(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
int		ft_checknumber(char	*argv);
int		ft_isdigit(int a);
void	ft_getlist(char **argv);
void	ft_error(int i);
int		ft_checkspaces(char *argv);
void	ft_lst_addback(t_cont **lst, int content);
void	ft_swap_a(t_cont *stack, int ss);
void	ft_swap_b(t_cont *stack, int ss);
void	ft_sswap(t_cont *stack_a, t_cont *stack_b);
void	ft_push_a(t_cont **stack_a, t_cont **stack_b);
void	ft_push_b(t_cont **stack_a, t_cont **stack_b);
void	ft_rotate_a(t_cont **stack_a);

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
