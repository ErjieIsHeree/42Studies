/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:23:15 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 19:26:41 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char **argv, int i)
{
	int	is_valid;

	is_valid = 1;
	while(argv[i])
		ft_atoi(argv[i++], &is_valid);
	return (is_valid);
}

int	check_flags(char **argv, int arg_id, int *bstrat, int *bbench)
{	
	if (!argv[arg_id])
		return (0);
	if (ft_strcmp(argv[arg_id], "--simple") == 0)
		return (simple_check(bstrat), 1);
	else if (ft_strcmp(argv[arg_id], "--medium") == 0)
		return (medium_check(bstrat), 1);
	else if (ft_strcmp(argv[arg_id], "--complex") == 0)
		return (complex_check(bstrat), 1);
	else if (ft_strcmp(argv[arg_id], "--adaptative") == 0)
		return (adaptative_check(bstrat), 1);
	else if (ft_strcmp(argv[arg_id], "--bench") == 0)
		return (bench_init(argv, bbench), 1);
	else
		return(is_number(argv, arg_id));
	return (0);
}

int		check(int argc, char **argv)
{
	int	arg_id;
	int	bstrat;
	int	bbench;

	(void)argc;
	arg_id = 0;
	bstrat = 0;
	bbench = 0;

	
	
	// if (check_flags(argv, ++arg_id, &bstrat, &bbench) != -1)
	// {
	// 	if(check_flags(argv, ++arg_id, &bstrat, &bbench) != -1)
	// 		check_flags(argv, ++arg_id, &bstrat, &bbench);
	// }
	return (check_flags(argv, ++arg_id, &bstrat, &bbench));
}