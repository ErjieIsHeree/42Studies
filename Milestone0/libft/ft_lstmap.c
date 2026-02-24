/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:35 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 18:10:54 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*new;
	void	*new_content;

	if (!del)
		return (NULL);
	t = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&t, del);
			return (NULL);
		}
		ft_lstadd_back(&t, new);
		lst = lst->next;
	}
	return (t);
}
