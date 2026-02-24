/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:10:23 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 12:14:58 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_alg(t_bench **bench, t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*temp;
	int		min;

	stack_b = NULL;
	temp = stack_b;
	while (*stack_a)
	{
		min = look_for_min(stack_a);
		while ((*stack_a)->value != min)
			ra(stack_a, bench);
		pb(stack_a, &stack_b, bench);
		if (stack_b && stack_b->next)
			sb(&stack_b, bench);
	}
	rb(&stack_b, bench);
	while (stack_b)
		pa(stack_a, &stack_b, bench);
	return (0);
}

void	medium_alg(t_bench **bench, t_stack **stack_a)
{
	t_stack		*stack_b;
	int			*arr;
	int			size;
	t_stacks	s;

	stack_b = NULL;
	size = ft_lstsize_u(*stack_a);
	arr = normalize_list(stack_a);
	s.a = stack_a;
	s.b = &stack_b;
	s.bench = bench;
	push_chunks_to_b(s, arr, size);
	push_back_to_a(s);
	free(arr);
}

static void	process_bit(t_stacks s, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_bit_set((*s.a)->index, bit))
			ra(s.a, s.bench);
		else
			pb(s.a, s.b, s.bench);
		i++;
	}
	while (*s.b)
		pa(s.a, s.b, s.bench);
}

int	complex_alg(t_bench **bench, t_stack **stack_a)
{
	t_stack		*stack_b;
	t_stacks	s;
	int			size;
	int			bit;
	int			*array;

	stack_b = NULL;
	size = ft_lstsize_u(*stack_a);
	array = normalize_list(stack_a);
	free(array);
	s.a = stack_a;
	s.b = &stack_b;
	s.bench = bench;
	bit = 0;
	while (bit < get_max_bits(stack_a))
	{
		process_bit(s, bit, size);
		bit++;
	}
	return (0);
}

int	adaptative_alg(t_bench **bench, t_stack **stack_a)
{
	bench_start(bench, stack_a);
	if ((*bench)->disorder_int < 20)
	{
		(*bench)->strat = 1;
		simple_alg(bench, stack_a);
	}
	else if ((*bench)->disorder_int > 20 && (*bench)->disorder_int < 50)
	{
		(*bench)->strat = 2;
		medium_alg(bench, stack_a);
	}
	else
	{
		(*bench)->strat = 3;
		complex_alg(bench, stack_a);
	}
	return (0);
}
