/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_f2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:43:36 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 23:53:53 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	in_chunk_range(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	top_distance(t_stack *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	bottom_distance(t_stack *stack, int min, int max)
{
	int	pos;
	int	last;

	pos = 0;
	last = -1;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			last = pos;
		stack = stack->next;
		pos++;
	}
	return (last);
}

void	move_closest_to_b(t_stacks s, int min, int max)
{
	int	top;
	int	bottom;
	int	size;

	top = top_distance(*s.a, min, max);
	bottom = bottom_distance(*s.a, min, max);
	size = ft_lstsize_u(*s.a);
	if (top <= size - bottom)
		while (top-- > 0)
			ra(s.a, s.bench);
	else
	{
		bottom = size - bottom;
		while (bottom-- > 0)
			rra(s.a, s.bench);
	}
	pb(s.a, s.b, s.bench);
}

void	push_single_chunk(t_stacks s, int min_val, int max_val)
{
	while (in_chunk_range(*s.a, min_val, max_val))
		move_closest_to_b(s, min_val, max_val);
}
