/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:28:01 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 17:24:14 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **arr, int filled_spaces)
{
	int	i;

	i = 0;
	while (i < filled_spaces)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * This function counts the full size of string s until the
 * first character of c. Excluding the null terminating character
 */
static int	str_size(const char *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

/**
 * This function counts the number of strings will be left after
 * the split.
 * 
 * @return the number of strings
 */
static int	count_str(char const *s, char c)
{
	int	n_str;
	int	i;

	n_str = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			n_str++;
			while (*s && *s != c)
				s++;
			s--;
		}
		s++;
	}
	return (n_str);
}

int	create_splited_in(char **dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (*src)
	{
		if (*src != c && *src)
		{
			dest[i] = ft_substr(src, 0, str_size(src, c));
			if (!dest[i])
			{
				free_all(dest, i);
				return (0);
			}
			i++;
			while (*src != c && *src)
				src++;
			src--;
		}
		src++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		substrs_count;

	if (!s)
		return (0);
	substrs_count = count_str(s, c);
	str_arr = (char **)malloc((substrs_count + 1) * sizeof(char *));
	if (!str_arr)
		return (0);
	if (!create_splited_in(str_arr, s, c))
		return (0);
	str_arr[substrs_count] = NULL;
	return (str_arr);
}
