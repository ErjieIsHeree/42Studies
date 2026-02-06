/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:08:24 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 18:53:14 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	(*lst) = (*lst)->next;
	(temp)->next = (*lst)->next;
	(*lst)->next = temp;
}

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!(*a) || !(*b))
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
}

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;

	if (!(*lst) || !(*lst)->next)
		return ;
	first = *lst;
	*lst = (*lst)->next;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = *lst;
	while ((last->next))
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}
