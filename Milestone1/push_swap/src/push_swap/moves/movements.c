/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:08:24 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 14:13:27 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	(*lst) = (*lst)->next;
	(temp)->next = (*lst)->next;
	(*lst)->next = temp;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
}

void	rotate(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!(*lst) || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*prev;
	t_stack	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while ((last->next))
	{
		prev = last;
		last = last->next;
	}
	if (prev)
	{
		prev->next = NULL;
		last->next = *lst;
		*lst = last;
	}
}
