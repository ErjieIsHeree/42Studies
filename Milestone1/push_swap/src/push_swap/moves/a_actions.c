/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:12:57 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 12:28:38 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **lst, t_bench **bench)
{
	write(1, "sa\n", 3);
	swap(lst);
	(*bench)->sa++;
	(*bench)->total_ops++;
}

void	pa(t_stack **a, t_stack **b, t_bench **bench)
{
	write(1, "pa\n", 3);
	push(b, a);
	(*bench)->pa++;
	(*bench)->total_ops++;
}

void	ra(t_stack **lst, t_bench **bench)
{
	write(1, "ra\n", 3);
	rotate(lst);
	(*bench)->ra++;
	(*bench)->total_ops++;
}

void	rra(t_stack **lst, t_bench **bench)
{
	write(1, "rra\n", 4);
	reverse_rotate(lst);
	(*bench)->rra++;
	(*bench)->total_ops++;
}
