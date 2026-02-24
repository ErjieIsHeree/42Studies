/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:20:41 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 16:56:43 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	ch;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	s = &s[len];
	while (*s != ch && s && len-- > 0)
		s--;
	if (*s != ch)
		return (NULL);
	return ((char *)s);
}
