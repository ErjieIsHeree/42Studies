/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:27:30 by exia              #+#    #+#             */
/*   Updated: 2026/01/22 15:40:31 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		i;

	if (!s || !f)
		return (NULL);
	arr = malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		arr[i] = (*f)(i, *s);
		i++;
		s++;
	}
	arr[i] = '\0';
	return (arr);
}
