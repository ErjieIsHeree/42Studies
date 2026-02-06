/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:12:57 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:00:22 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sb(t_list **lst)
{
	swap(lst);
	ft_printf("sb\n");
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pb\n");
}

void	rb(t_list **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

void	rrb(t_list **lst)
{
	reverse_rotate(lst);
	ft_printf("rrb\n");
}
