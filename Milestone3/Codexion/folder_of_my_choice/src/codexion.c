/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 17:25:41 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE ALL COMMENTS BEFORE EVALUATION
/**
 * ERRORS:
 * 	-100: Args erros
 * 		-101 Too few/many args (8 required, 9 if count program name)
 * 		-110 Parsing errors
 * 		-120 Validating errors
 * 
 * 	100: Sync variables initialization errors
 * 		101 Failed to initialize some thread
 * 		102 Failed to initialize some mutex
 * 		103 Failed to initialize some cond
 */

#include "codexion.h"

int	codexion(int argc, char **argv)
{
	t_table	table;
	t_rules	rules;
	int		error;

	error = get_rules(argc, argv, &rules);
	if (error != 0)
		return error;
	error = codex_init(&rules, &table);
	if (error != 0)
		return (codex_destroy(&rules, &table, error));
	error = codex_start(&rules, &table);
	codex_destroy(&rules, &table, 0);
	return (error);
}
