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

void	simple(struct s_bench *bench, t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (stack_a->prev->value)
		{
			sa(&stack_a->prev);
		}
		stack_a = temp;
	}
}

void	medium(struct s_bench *bench, t_list *stack_a)
{
	
}

void	complex(struct s_bench *bench, t_list *stack_a)
{
	
}

void	adaptative(struct s_bench *bench, t_list *stack_a)
{
	
}
