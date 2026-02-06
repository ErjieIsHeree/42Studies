/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:18:06 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 18:04:51 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bench_init(char **argv, int *bench)
{
	(void)argv;
	if (*bench != 1)
		printf("\nStart benchmark\n");
	else
		return (printf("\nBenchmark error\n"), -1);
	*bench = 1;
	return (-1);
}