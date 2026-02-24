/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:38:00 by exia              #+#    #+#             */
/*   Updated: 2026/02/11 22:48:27 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_u(const char *str, int *is_valid)
{
	int		signo;
	long	solution;

	signo = 1;
	solution = 0;
	if (*str == '-')
	{
		signo = -1;
		str++;
	}
	if (!*str)
		return (*is_valid = 1, 0);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			solution = solution * 10 + (*str++ - '0');
		else
			return (*is_valid = 1, 0);
	}
	solution = solution * signo;
	if (solution > 2147483647 || solution < -2147483648)
		return (*is_valid = 1, 0);
	else
		return (solution);
}
