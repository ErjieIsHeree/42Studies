/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:29:09 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 16:28:51 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;

	if (n == 0)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	while (*sa && *sb && *sa == *sb && n-- > 1)
	{
		sa++;
		sb++;
	}
	return (*sa - *sb);
}
