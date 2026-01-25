/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:59 by exia              #+#    #+#             */
/*   Updated: 2026/01/22 17:23:59 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s1));
	else if (!s2)
		return (ft_strdup(s2));
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(&ptr[ft_strlen(s1)], s2, ft_strlen(s2));
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}
