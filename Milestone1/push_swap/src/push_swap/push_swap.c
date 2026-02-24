/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:25:27 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/08 23:14:21 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_alg(t_bench **bench, t_list **stack_a)
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
