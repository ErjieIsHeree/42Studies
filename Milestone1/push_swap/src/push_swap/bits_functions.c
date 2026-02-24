/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:56:22 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 12:13:03 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bit_set(int value, int bit)
{
	return ((value >> bit) & 1);
}

int	max_bits(int value)
{
	int	bits;

	bits = 0;
	while (value != 0)
	{
		value = value >> 1;
		bits++;
	}
	return (bits);
}

int	get_max_bits(t_stack **stack_a)
{
	t_stack	*temp;
	int		max;

	max = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max_bits(max));
}
