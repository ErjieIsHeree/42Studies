/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:28:54 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 12:58:08 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*sr;
	unsigned char		*des;

	if (!dest && !src)
		return (NULL);
	sr = (unsigned const char *)src;
	des = (unsigned char *)dest;
	while (n--)
		des[n] = sr[n];
	return (dest);
}
