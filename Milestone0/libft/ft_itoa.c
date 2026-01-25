/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:33:55 by exia              #+#    #+#             */
/*   Updated: 2026/01/23 13:14:40 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function returns the number of chars needed to fully represent n.
 * (Including the negative character and the null terminating for strings)
 *
 * @param n the number
 * @return the amount of char spaces need to representate n
 */
static int	get_full_size(int n)
{
	int	n_size;
	int	full_size;
	int	a;

	if (n == 0)
		return (2);
	full_size = 1;
	if (n < 0)
		full_size++;
	a = 1;
	n_size = 0;
	while (n / a != 0 && n_size < 10)
	{
		n_size++;
		a *= 10;
	}
	full_size += n_size;
	return (full_size);
}

static void	transform_n(char *c, int n)
{
	int	i;
	int	div;
	int	alone_n;

	i = 0;
	if (n < 0)
		c[i++] = '-';
	div = 1000000000;
	while (n / div == 0)
		div /= 10;
	while (div > 0)
	{
		alone_n = ((n / div) % 10);
		if (alone_n < 0)
			c[i++] = '0' + alone_n * (-1);
		else
			c[i++] = '0' + alone_n;
		div /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*c;
	size_t	full_size;

	full_size = get_full_size(n);
	c = malloc(full_size);
	if (!c)
		return (NULL);
	if (n == 0)
	{
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	transform_n(c, n);
	c[full_size - 1] = '\0';
	return (c);
}
