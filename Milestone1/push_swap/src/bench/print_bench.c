/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:51:40 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:01:53 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_bench **bench)
{
	if (!bench || !*bench)
		return ;
	if ((*bench)->strat == 1)
		(*bench)->math_name = "(O(n2))";
	else if ((*bench)->strat == 2)
		(*bench)->math_name = "(O(n√n))";
	else if ((*bench)->strat == 3)
		(*bench)->math_name = "(O(n log n))";
	ft_dprintf(2, "[bench] disorder:	%i.%i%%\n", (*bench)->disorder_int,
		(*bench)->disorder_dec);
	ft_dprintf(2, "[bench] strategy:	%s \\ %s\n", (*bench)->strat_name,
		(*bench)->math_name);
	ft_dprintf(2, "[bench] total ops:	%i\n", (int)(*bench)->total_ops);
	ft_dprintf(2, "[bench] sa:	%i\t", (int)(*bench)->sa);
	ft_dprintf(2, "sb:	%i\t", (int)(*bench)->sb);
	ft_dprintf(2, "ss:	%i\t", (int)(*bench)->ss);
	ft_dprintf(2, "pa:	%i\t", (int)(*bench)->pa);
	ft_dprintf(2, "pb:	%i\n", (int)(*bench)->pb);
	ft_dprintf(2, "[bench] ra:	%i\t", (int)(*bench)->ra);
	ft_dprintf(2, "rb:	%i\t", (int)(*bench)->rb);
	ft_dprintf(2, "rr:	%i\t", (int)(*bench)->rr);
	ft_dprintf(2, "rra:	%i\t", (int)(*bench)->rra);
	ft_dprintf(2, "rrb:	%i\t", (int)(*bench)->rrb);
	ft_dprintf(2, "rrr:	%i\n", (int)(*bench)->rrr);
}
