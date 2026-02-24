/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:12:57 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 12:28:40 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, t_bench **bench)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
	(*bench)->ss++;
	(*bench)->total_ops++;
}

void	rr(t_stack **a, t_stack **b, t_bench **bench)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
	(*bench)->rr++;
	(*bench)->total_ops++;
}

void	rrr(t_stack **a, t_stack **b, t_bench **bench)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
	(*bench)->rrr++;
	(*bench)->total_ops++;
}
