/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:14:58 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 12:32:23 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char **argv, t_stack **stack_a, t_bench **bench)
{
	int			arg_id;
	static int	bstrat;
	static int	bbench;

	bstrat = 0;
	arg_id = 1;
	if (!parse_initial_flags(argv, &arg_id, &bstrat, &bbench))
		return (1);
	if (!validate_remaining(argv, arg_id) || !argv[arg_id]
		|| !is_number(argv, arg_id, stack_a))
		return (1);
	apply_flags_and_strategy(bbench, bstrat, bench);
	return (check_rep_number(stack_a, bench), 0);
}
