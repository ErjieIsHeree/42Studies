/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:27:17 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 13:42:25 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	int				disorder_dec;
	int				disorder_int;
	int				strat;
	char			*strat_name;
	char			*math_name;
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

typedef struct s_stacks
{
	t_stack			**a;
	t_stack			**b;
	t_bench			**bench;
}					t_stacks;

/*--- ALGORITHM ---*/
int					execute_alg(t_bench **bench, t_stack **stack_a);
/* movements */
void				swap(t_stack **lst);
void				push(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **lst);
void				rotate(t_stack **lst);

/* calls */
int					adaptative_alg(t_bench **bench, t_stack **stack_a);
int					complex_alg(t_bench **bench, t_stack **stack_a);
void				medium_alg(t_bench **bench, t_stack **stack_a);
int					simple_alg(t_bench **bench, t_stack **stack_a);

/* a actions*/
void				sa(t_stack **lst, t_bench **bench);
void				pa(t_stack **a, t_stack **b, t_bench **bench);
void				ra(t_stack **lst, t_bench **bench);
void				rra(t_stack **lst, t_bench **bench);

/* b actions*/
void				sb(t_stack **lst, t_bench **bench);
void				pb(t_stack **a, t_stack **b, t_bench **bench);
void				rb(t_stack **lst, t_bench **bench);
void				rrb(t_stack **lst, t_bench **bench);

/* multiple actions*/
void				ss(t_stack **a, t_stack **b, t_bench **bench);
void				rr(t_stack **a, t_stack **b, t_bench **bench);
void				rrr(t_stack **a, t_stack **b, t_bench **bench);

/*--- Checker ---*/
int					check(char **argv, t_stack **stack_a, t_bench **bench);
int					check_flags(char **argv, int arg_id, int *bstrat,
						int *bbench);
int					is_number(char **argv, int arg_id, t_stack **stack_a);
int					check_rep_number(t_stack **stack_a, t_bench **bench);
void				fatal_error(void);

/* algorithm check */
int					adaptative_check(int *bstrat);
int					complex_check(int *bstrat);
int					medium_check(int *bstrat);
int					simple_check(int *bstrat);
int					*normalize_list(t_stack **stack_a);
void				push_back_to_a(t_stacks s);
void				push_chunks_to_b(t_stacks s, int *arr, int total_size);
int					look_max(t_stack *stack);
void				push_chunks_to_b(t_stacks s, int *arr, int total_size);
void				push_back_to_a(t_stacks s);

/* utils */
int					look_for_min(t_stack **lst);
int					look_for_max(t_stack **lst);
void				push_b_chunk(t_bench *bench, t_stack **stack_a,
						t_stack **stack_b, size_t chunk_size);
void				push_back_ordered(t_bench *bench, t_stack **stack_a,
						t_stack **stack_b);
size_t				root(size_t a);
int					check_if_ordered(t_stack **stack_a);
void				push_single_chunk(t_stacks s, int min_val, int max_val);
void				cleanup_and_fatal(t_stack **stack_a, t_bench **bench);
/* bits */
int					is_bit_set(int value, int bit);
int					count_bits(int value);
int					max_bits(int value);
int					get_max_bits(t_stack **stack_a);

/*--- BENCH ---*/
int					bench_init(char **argv, int *bench);
void				bench_start(t_bench **bench, t_stack **stack_a);
t_bench				*select_strat(int bstrat, t_bench **bench);
float				calculate_disorder(t_stack **stack_a);
void				print_bench(t_bench **bench);

/* printf */
int					ft_dprintf(int fd, char const *str, ...);
void				putchr_fd(int fd, char c, int *w_size);
void				putstr_fd(int fd, char *str, int *w_size);
void				putnbr_base_fd(int fd, unsigned long nbr, char *base,
						int *w_size);
void				putnbr_fd(int fd, int nbr, char *base, int *w_size);
void				putptr_hexa_fd(int fd, void *ptr, int *w_size);
void				putchr(char c, int *w_size);
void				putstr(char *str, int *w_size);
void				putnbr_base(unsigned long nbr, char *base, int *w_size);
void				putnbr(int nbr, char *base, int *w_size);
void				putptr_hexa(void *ptr, int *w_size);
int					printf_strlen(char *str);

/*--- FREE ---*/
void				free_stack(t_stack **stack);

/*--- UTILS---*/
int					parse_int_str(const char *s, int *is_valid);
t_stack				*ft_lstnew_u(int value);
int					ft_lstsize_u(t_stack *lst);
int					is_str_number(const char *s);
int					validate_remaining(char **argv, int start);
int					append_node_to_stack(t_stack **stack_a, t_stack **tail,
						int val);
int					parse_initial_flags(char **argv, int *arg_id, int *bstrat,
						int *bbench);
void				apply_flags_and_strategy(int bbench, int bstrat,
						t_bench **bench);

#endif