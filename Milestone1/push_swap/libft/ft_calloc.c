/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:06:20 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/05 17:06:21 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc((nmemb * size));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ((nmemb * size)))
	{
		ptr[i++] = (unsigned char)(0);
	}
	return (ptr);
}