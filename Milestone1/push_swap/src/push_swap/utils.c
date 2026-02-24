/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:23:07 by exia              #+#    #+#             */
/*   Updated: 2026/02/12 11:53:14 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	look_for_min(t_stack **lst)
{
	t_stack	*temp;
	int		min;

	temp = *lst;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int	check_if_ordered(t_stack **stack_a)
{
	t_stack	*node;

	node = *stack_a;
	while (node && node->next)
	{
		if (node->value > (node->next->value))
			return (1);
		node = node->next;
	}
	return (0);
}

void	fatal_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	cleanup_and_fatal(t_stack **stack_a, t_bench **bench)
{
	if (stack_a)
		free_stack(stack_a);
	if (*bench)
		free(*bench);
	fatal_error();
}
