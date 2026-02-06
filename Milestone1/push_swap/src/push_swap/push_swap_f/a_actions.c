/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:12:57 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:25:07 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sa(t_list **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}
