/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:19:43 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 12:35:30 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_check(int *bstrat)
{
	if (*bstrat)
		return (1);
	return (*bstrat = 1, 0);
}

int	medium_check(int *bstrat)
{
	if (*bstrat)
		return (1);
	return (*bstrat = 2, 0);
}

int	complex_check(int *bstrat)
{
	if (*bstrat)
		return (1);
	return (*bstrat = 3, 0);
}

int	adaptative_check(int *bstrat)
{
	if (*bstrat)
		return (1);
	return (*bstrat = 4, 0);
}

int	bench_init(char **argv, int *bbench)
{
	(void)argv;
	if (*bbench)
		return (1);
	return (*bbench = 1, 0);
}
