/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:43:36 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:05:09 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_chunks_to_b(t_stacks s, int *arr, int total_size)
{
	int	chunks;
	int	size;
	int	i;
	int	min_idx;
	int	max_idx;

	(void)arr;
	if (total_size <= 50)
		chunks = 2;
	else if (total_size <= 100)
		chunks = 6;
	else
		chunks = 11;
	size = total_size / chunks;
	i = 0;
	while (i < chunks)
	{
		min_idx = i * size;
		if (i == chunks - 1)
			max_idx = total_size - 1;
		else
			max_idx = (i + 1) * size - 1;
		push_single_chunk(s, min_idx, max_idx);
		i++;
	}
}

int	look_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static void	rotate_to_max(t_stacks s, int max, int size)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *s.b;
	while (tmp && tmp->value != max)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
		while (*s.b && (*s.b)->value != max)
			rb(s.b, s.bench);
	else
	{
		pos = size - pos;
		while (*s.b && (*s.b)->value != max)
			rrb(s.b, s.bench);
	}
}

void	push_back_to_a(t_stacks s)
{
	int	max;
	int	size;

	while (*s.b)
	{
		max = look_max(*s.b);
		size = ft_lstsize_u(*s.b);
		rotate_to_max(s, max, size);
		if (*s.b)
			pa(s.a, s.b, s.bench);
	}
}
