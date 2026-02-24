/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:25:27 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/10 19:19:31 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_alg(t_bench **bench, t_stack **stack_a)
{
	if ((*bench)->use_bench)
		bench_start(bench, stack_a);
	if ((*bench)->strat == 1)
		return (simple_alg(bench, stack_a), 1);
	if ((*bench)->strat == 2)
		return (medium_alg(bench, stack_a), 1);
	if ((*bench)->strat == 3)
		return (complex_alg(bench, stack_a), 1);
	if ((*bench)->strat == 4)
		return (adaptative_alg(bench, stack_a), 1);
	return (1);
}
