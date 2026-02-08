/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:10:23 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:36:56 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	mini_bubble(struct s_bench *bench, t_list **stack_a, t_list **stack_b)
{
	if ()
}

/**
 * This function is an adaptation of the "selection sort" algorithm to this
 * push_swap function.
 * 
 * The original function brings to the start of the stack the smallest
 */
void	simple(struct s_bench *bench, t_list *stack_a, t_list *stack_b)
{
	while (check(stack_a))
	{
		while (stack_a)
			if (stack_a->next)
				mini_bubble(bench, &stack_a, &stack_b);
			else
				pb()
		while (stack_b)
			bubble_sort_b(bench, &stack_a, &stack_b);
	}
}

/*
void	medium(struct s_bench *bench, t_list *stack_a)
{
	
}

void	complex(struct s_bench *bench, t_list *stack_a)
{
	
}

void	adaptative(struct s_bench *bench, t_list *stack_a)
{
	
}
*/
