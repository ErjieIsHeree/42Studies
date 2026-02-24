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

char	*strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_l;
	size_t	s2_l;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s1));
	else if (!s2)
		return (ft_strdup(s2));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	new_str = ft_calloc(s1_l + s2_l + 1, 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s1, s1_l);
	ft_memmove(&new_str[s1_l], s2, s2_l);
	new_str[s1_l + s2_l] = 0;
	return (new_str);
}
