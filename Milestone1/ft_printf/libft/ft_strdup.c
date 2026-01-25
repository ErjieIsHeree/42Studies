/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:48:23 by exia              #+#    #+#             */
/*   Updated: 2026/01/16 17:18:47 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_size;

	s_size = ft_strlen(s);
	ptr = malloc(s_size + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, s_size + 1);
	return (ptr);
}
