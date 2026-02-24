/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:08:03 by exia              #+#    #+#             */
/*   Updated: 2026/01/21 11:23:16 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	j = ft_strlen(dst);
	while (i + j < size - 1 && src[i] != '\0')
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + j);
}
