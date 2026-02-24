/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_strat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:53:03 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/10 14:28:09 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*select_strat(int bstrat, t_bench **bench)
{
	if (bstrat == 1)
	{
		(*bench)->strat = 1;
		(*bench)->strat_name = "Simple";
	}
	else if (bstrat == 2)
	{
		(*bench)->strat = 2;
		(*bench)->strat_name = "Medium";
	}
	else if (bstrat == 3)
	{
		(*bench)->strat = 3;
		(*bench)->strat_name = "Complex";
	}
	else
	{
		(*bench)->strat = 4;
		(*bench)->strat_name = "Adaptative";
	}
	return (*bench);
}
