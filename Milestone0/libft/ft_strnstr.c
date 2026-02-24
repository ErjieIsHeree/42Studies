/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:20:17 by exia              #+#    #+#             */
/*   Updated: 2026/01/14 13:37:30 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len-- >= ft_strlen(little))
	{
		i = 0;
		while (big[i] == little[i] || little[i] == '\0')
		{
			if (little[i] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
	}
	return (NULL);
}
