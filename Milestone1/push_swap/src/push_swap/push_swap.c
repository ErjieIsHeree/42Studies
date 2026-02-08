/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:36:26 by exia              #+#    #+#             */
/*   Updated: 2026/02/06 20:19:02 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push_swap(struct s_bench *bench, t_list *stack_a)
{
	t_list	*stack_b;

	if(!init_stack(&stack_b))
		return (0);
	if (bench->strat == SIMPLE)
		simple(bench, stack_a, stack_b);
	else if (bench->strat == MEDIUM)
		medium(bench, stack_a, stack_b);
	else if (bench->strat == COMPLEX)
		complex(bench, stack_a, stack_b);
	else
		adaptative(bench, stack_a, stack_b);
	free_stack(&stack_b);
	return (1);
}
