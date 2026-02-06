/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 19:19:43 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:20:36 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_check(int *bstrat)
{
	if (*bstrat)
		printf("\nStrat Error\n");
	else
		printf("\nStart simple algorithm\n");
	return (*bstrat = 1, -1);
}

int	medium_check(int *bstrat)
{
	if (*bstrat)
		printf("\nStrat Error\n");
	else
		printf("\nStart medium algorithm\n");
	return (*bstrat = 1, -1);
}

int	complex_check(int *bstrat)
{
	if (*bstrat)
		printf("\nStrat Error\n");
	else
		printf("\nStart complex algorithm\n");
	return (*bstrat = 1, -1);
}

int	adaptative_check(int *bstrat)
{
	if (*bstrat)
		printf("\nStrat Error\n");
	else
		printf("\nStart adaptative algorithm\n");
	return (*bstrat = 1, -1);
}