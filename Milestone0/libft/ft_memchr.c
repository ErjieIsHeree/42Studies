/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:57:12 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 17:06:17 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (!s || !n)
		return (NULL);
	temp = (unsigned char *)s;
	while (*temp != (unsigned char)c && n-- > 1)
		temp++;
	if (*temp == (unsigned char)c)
		return ((void *)temp);
	return (NULL);
}
