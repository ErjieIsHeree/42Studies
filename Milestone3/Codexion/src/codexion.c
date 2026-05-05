/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/06 00:12:39 by erjieishere      ###   ########.fr       */
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
 * 	200: Thread run-time errors
 * 	300: Sync variables destroying errors 
 */

#include "codexion.h"

int	codex_init(t_rules *codex_rules, t_table *table)
{
	return (0);
}

int	codex_destroy(t_table *table)
{
	return (0);
}

int	codexion(int argc, char **argv)
{
	t_table	table;
	t_rules	codex_rules;
	int		error;

	error = get_rules(argc, argv, &codex_rules);
	if (error != 0)
		return error;
	error = codex_init(&codex_rules, &table);
	if (error != 0)
		return error;
	error = codex_start(&codex_rules, &table);
	if (error != 0)
		return error;
	error = codex_destroy(&table);
	if (error != 0)
		return error;
	return 0;
}
