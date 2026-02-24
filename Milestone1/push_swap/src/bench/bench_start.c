/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:23:34 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 14:08:44 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_disorder(t_stack **stack_a)
{
	t_stack	*i_node;
	t_stack	*j_node;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i_node = *stack_a;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			if (i_node->value > j_node->value)
				mistakes++;
			total_pairs++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}

void	bench_start(t_bench **bench, t_stack **stack_a)
{
	float	disorder_float;
	int		disorder_int;
	int		disorder_dec;

	disorder_float = calculate_disorder(stack_a);
	disorder_int = (int)(disorder_float * 100);
	disorder_dec = (int)(disorder_float * 10000) % 100;
	(*bench)->disorder_int = disorder_int;
	(*bench)->disorder_dec = disorder_dec;
	(*bench)->total_ops = 0;
	(*bench)->sa = 0;
	(*bench)->sb = 0;
	(*bench)->ss = 0;
	(*bench)->pa = 0;
	(*bench)->pb = 0;
	(*bench)->ra = 0;
	(*bench)->rb = 0;
	(*bench)->rr = 0;
	(*bench)->rra = 0;
	(*bench)->rrb = 0;
	(*bench)->rrr = 0;
}
