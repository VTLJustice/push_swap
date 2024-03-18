/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:04:53 by rradules          #+#    #+#             */
/*   Updated: 2024/03/14 19:06:04 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef SA
#  define SA 0
# endif

# ifndef SB
#  define SB 1
# endif

# ifndef PA
#  define PA 0
# endif

# ifndef PB
#  define PB 1
# endif

# ifndef RA
#  define RA 0
# endif

# ifndef RB
#  define RB 1
# endif

# ifndef RRA
#  define RRA 0
# endif

# ifndef RRB
#  define RRB 0
# endif

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
void	ft_getlist(char **argv, t_cont **stack);
void	ft_error(void);
int		ft_checkspaces(char *argv);
void	ft_lst_addback(t_cont **lst, int content);
void	ft_normalize(t_cont **stack);
void	*ft_memset(void *str, size_t c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
t_cont	*ft_lstlast(t_cont *lst);

/* push_swap utilities */
void	ft_printstacks(t_cont *stack_a, t_cont *stack_b);
int		ft_count_numbers(t_cont *stack);

/* push_swap algorithim */
void	ft_start_alg(t_cont **stack);
void	ft_swap(t_cont *stack, int swap);
void	ft_sswap(t_cont *stack_a, t_cont *stack_b);
void	ft_push(t_cont **host, t_cont **newcomer, int push);
void	ft_rotate(t_cont **stack, int rotate);
void	ft_rrotate(t_cont **stack_a, t_cont **stack_b);
void	ft_reverse_rotate(t_cont **stack, int reverse_rotate);
void	ft_rr_rotate(t_cont **stack_a, t_cont **stack_b);
int		ft_check_order(t_cont *stack);
int		ft_check_order_b(t_cont *stack);
void	ft_sort_three(t_cont **stack);
void	ft_end(t_cont **stack);

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
