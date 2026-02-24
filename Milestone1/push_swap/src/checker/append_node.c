/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:15:15 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:15:34 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_node_to_stack(t_stack **stack_a, t_stack **tail, int val)
{
	t_stack	*node;

	node = ft_lstnew_u(val);
	if (!node)
		return (0);
	if (!*stack_a)
	{
		*stack_a = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
	return (1);
}
