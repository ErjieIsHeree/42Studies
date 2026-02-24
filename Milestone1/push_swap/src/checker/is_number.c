/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:14:22 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:14:23 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **argv, int i, t_stack **stack_a)
{
	t_stack	*tail;
	int		valid;
	int		val;

	tail = NULL;
	while (argv[i])
	{
		val = parse_int_str(argv[i], &valid);
		if (!valid)
			return (free_stack(stack_a), 0);
		if (!append_node_to_stack(stack_a, &tail, val))
			return (free_stack(stack_a), 0);
		i++;
	}
	return (1);
}
