/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:27:17 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:56:14 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef	enum	e_strat
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE
}	t_strat;

typedef struct s_bench
{
	int				disorder;
	enum	e_strat	strat;
	size_t			total_ops;
	size_t			sa;
	size_t			sb;
	size_t			ss;
	size_t			pa;
	size_t			pb;
	size_t			ra;
	size_t			rb;
	size_t			rr;
	size_t			rra;
	size_t			rrb;
	size_t			rrr;
	int				use_bench;
}					t_bench;

/*--- LIBFT ---*/
t_list				*ft_lstnew(int value);
size_t				ft_strcmp(char *s1, char *s2);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *str, int *is_valid);

/* printf */
int					ft_printf(char const *str, ...);
void				sum(int *i, int ammount);
void				ft_putchar(char c, int *i_sum);
void				ft_putnbr(int nb, int *i_sum);
void				ft_putunsnbr(unsigned int nb, int *i_sum);
void				ft_putstr(const char *str, int *i_sum);

/*--- ALGORITHM ---*/
/* movements */
void				swap(t_list **lst);
void				push(t_list **a, t_list **b);
void				reverse_rotate(t_list **lst);
void				rotate(t_list **lst);

/* calls */
int					adaptative_alg(char **argv, int *bstrat);
int					complex_alg(char **argv, int *bstrat);
int					medium_alg(char **argv, int *bstrat);
int					simple_alg(char **argv, int *bstrat);

/* a actions*/
void				sa(t_list **lst);
void				pa(t_list **a, t_list **b);
void				ra(t_list **lst);
void				rra(t_list **lst);

/* b actions*/
void				sb(t_list **lst);
void				pb(t_list **a, t_list **b);
void				rb(t_list **lst);
void				rrb(t_list **lst);

/* multiple actions*/
void				rr(t_list **a, t_list **b);
void				rrr(t_list **a, t_list **b);

/*--- PARSE ---*/
t_list				*parse_args(int argc, char **argv, t_bench *bench, t_list *stack_a);
int					recognize_flags(char **argv, t_bench *bench, t_list **stack_a, int i, int *bstrat);
void				recognize_number(char **argv, int i, t_list **head);

/*--- Checker ---*/
int					check(int argc, char **argv);
int					check_flags(char **argv, int i, int *bstrat, int *bbench);
int					is_number(char **argv, int arg_id);
//int					recognize_number(char **argv, int i);
/* algorithm check */
int					adaptative_check(int *bstrat);
int					complex_check(int *bstrat);
int					medium_check(int *bstrat);
int					simple_check(int *bstrat);

/*--- BENCH ---*/
int					bench_init(char **argv, int *bench);

#endif