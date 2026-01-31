/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:01:10 by exia              #+#    #+#             */
/*   Updated: 2026/01/31 20:41:04 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*j;

	j = s;
	while (n-- > 0)
	{
		j[n] = '\0';
	}
}

size_t	ft_strlen_c(const char *s, const char c)
{
	size_t	quantity;

	quantity = 0;
	while (*s && *s++ != c)
		quantity++;
	if (*s == c)
		quantity++;
	return (quantity);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_size;
	int		i;

	s_size = ft_strlen_c(s, '\0');
	ptr = malloc(s_size + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
		ptr[i] = s[i++];
	ptr[i] = 0;
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (ULONG_MAX / size < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
