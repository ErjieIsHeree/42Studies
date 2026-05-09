/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 20:14:09 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE ALL COMMENTS BEFORE EVALUATION
/**
 * ERRORS:
 * 	300: Args erros
 * 		301 Too few/many args (8 required, 9 if count program name)
 * 		310 Parsing errors
 * 		320 Validating errors
 * 
 * 	100: Sync variables initialization errors
 * 		101 Failed to initialize some thread
 * 		102 Failed to initialize some mutex
 * 		103 Failed to initialize some cond
 * 		104 Failed to allocate memory
 * 
 * 	200: Coders threads running errors
 * 		201 Failed to initialize monitor thread
 */

#include "codexion.h"

int	codexion(int argc, char **argv)
{
	t_table	table;
	t_rules	rules;
	int		error;

	error = get_rules(argc, argv, &rules);
	if (error != 0)
		return (error);
	error = codex_init(&rules, &table);
	if (error != 0)
		return (codex_destroy(&rules, &table, error));
	error = codex_start(&rules, &table);
	codex_destroy(&rules, &table, 0);
	printf("\n%p, %p, %p", table.coder, table.dongle, table.dongle_cond);
	return (error);
}
