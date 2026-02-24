/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:12:57 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 12:28:43 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **lst, t_bench **bench)
{
	write(1, "sb\n", 3);
	swap(lst);
	(*bench)->sb++;
}

void	pb(t_stack **a, t_stack **b, t_bench **bench)
{
	write(1, "pb\n", 3);
	push(a, b);
	(*bench)->pb++;
	(*bench)->total_ops++;
}

void	rb(t_stack **lst, t_bench **bench)
{
	write(1, "rb\n", 3);
	rotate(lst);
	(*bench)->rb++;
	(*bench)->total_ops++;
}

void	rrb(t_stack **lst, t_bench **bench)
{
	write(1, "rrb\n", 4);
	reverse_rotate(lst);
	(*bench)->rrb++;
	(*bench)->total_ops++;
}
