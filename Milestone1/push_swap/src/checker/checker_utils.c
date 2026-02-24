/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:05:28 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 12:23:02 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_remaining(char **argv, int start)
{
	int	k;

	k = start;
	while (argv[k])
	{
		if (!is_str_number(argv[k]))
			return (0);
		k++;
	}
	return (1);
}

void	apply_flags_and_strategy(int bbench, int bstrat, t_bench **bench)
{
	if (bbench)
		(*bench)->use_bench = 1;
	select_strat(bstrat, bench);
}
