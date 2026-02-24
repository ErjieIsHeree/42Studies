/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:42:42 by exia              #+#    #+#             */
/*   Updated: 2026/01/22 16:25:20 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		s_o_end;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	s_o_end = 0;
	while (ft_strchr(set, s1[ft_strlen(s1) - s_o_end - 1]))
		s_o_end++;
	return (ft_substr(s1, start, ft_strlen(s1) - start - s_o_end));
}
