/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:38:00 by exia              #+#    #+#             */
/*   Updated: 2026/01/22 18:40:37 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	is_negative;
	int	has_n;

	is_negative = 0;
	n = 0;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = 1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		n = n * 10 + (*nptr++ - 48);
		has_n = 1;
	}
	if (is_negative)
		n *= -1;
	if (has_n)
		return (n);
	return (0);
}
