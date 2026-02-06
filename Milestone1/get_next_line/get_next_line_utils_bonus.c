/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:01:10 by exia              #+#    #+#             */
/*   Updated: 2026/02/04 14:23:02 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strjoin(char *s1, char *s2, size_t size)
{
	char	*new_str;
	size_t	s1_l;
	size_t	s2_l;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s1));
	else if (!s2)
		return (ft_strdup(s2));
	s1_l = ft_strlen(s1);
	s2_l = size;
	new_str = ft_calloc(s1_l + s2_l + 1, 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s1, s1_l);
	ft_memmove(&new_str[s1_l], s2, s2_l);
	new_str[s1_l + s2_l] = 0;
	return (new_str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*sr;
	unsigned char		*des;
	size_t				i;

	sr = src;
	des = dest;
	i = 0;
	if (src < dest)
	{
		while (i < n)
		{
			des[n - 1] = sr[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			des[i] = sr[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	quantity;

	quantity = 0;
	while (*s++)
		quantity++;
	return (quantity);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

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

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_size;
	int		i;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	ptr = ft_calloc(s_size + 1, 1);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
