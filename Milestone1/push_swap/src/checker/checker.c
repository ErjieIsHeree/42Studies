/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:25:01 by exia              #+#    #+#             */
/*   Updated: 2026/02/12 13:42:44 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_and_exit(t_stack **stack_a, t_bench **bench)
{
	if ((*bench)->use_bench)
	{
		bench_start(bench, stack_a);
		print_bench(bench);
	}
	free_stack(stack_a);
	free(*bench);
	exit(0);
}

int	check_rep_number(t_stack **stack_a, t_bench **bench)
{
	t_stack	*i;
	t_stack	*j;

	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				cleanup_and_fatal(stack_a, bench);
			j = j->next;
		}
		i = i->next;
	}
	if (!check_if_ordered(stack_a))
		cleanup_and_exit(stack_a, bench);
	return (1);
}

int	check_flags(char **argv, int arg_id, int *bstrat, int *bbench)
{
	if (!argv[arg_id])
		return (1);
	if (ft_strncmp(argv[arg_id], "--simple", 9) == 0)
		return (simple_check(bstrat));
	else if (ft_strncmp(argv[arg_id], "--medium", 9) == 0)
		return (medium_check(bstrat));
	else if (ft_strncmp(argv[arg_id], "--complex", 10) == 0)
		return (complex_check(bstrat));
	else if (ft_strncmp(argv[arg_id], "--adaptative", 13) == 0)
		return (adaptative_check(bstrat));
	else if (ft_strncmp(argv[arg_id], "--bench", 8) == 0)
		return (bench_init(argv, bbench));
	if (argv[arg_id] && argv[arg_id][0] == '-')
		fatal_error();
	return (1);
}
