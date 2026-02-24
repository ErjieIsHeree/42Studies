/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:14:36 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:14:37 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_initial_flags(char **argv, int *arg_id, int *bstrat, int *bbench)
{
	while (*arg_id <= 2 && argv[*arg_id])
	{
		if (argv[*arg_id][0] == '-' && argv[*arg_id][1] == '-')
		{
			if (check_flags(argv, *arg_id, bstrat, bbench) != 0)
				return (0);
			(*arg_id)++;
			continue ;
		}
		if (is_str_number(argv[*arg_id]))
			break ;
		return (0);
	}
	return (1);
}
