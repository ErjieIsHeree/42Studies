/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:09:15 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 17:00:53 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;

	if (n == 0 || !s1 || !s2)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	while (*sa == *sb && n-- > 1)
	{
		sa++;
		sb++;
	}
	return (*sa - *sb);
}
