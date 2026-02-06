/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:02:13 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:47:46 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int *is_valid)
{
	int		signo;
	long	solution;
	
	signo = 1;
	solution = 0;
	(void)is_valid;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signo = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			solution = solution * 10 + (*str++ - '0');
		else
			return (*is_valid = 0, 0);
	}
	solution = solution * signo;
	if (solution > 2147483647|| solution < -2147483648)
		return (*is_valid = 0, 0);
	else
		return (solution);
}
