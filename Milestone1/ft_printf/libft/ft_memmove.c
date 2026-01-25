/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:42:18 by exia              #+#    #+#             */
/*   Updated: 2026/01/16 16:10:08 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*sr;
	unsigned char		*des;
	int					i;

	sr = src;
	des = dest;
	i = 0;
	if (src < dest)
	{
		while (i < (int)n)
		{
			des[n - 1] = sr[n - 1];
			n--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			des[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
