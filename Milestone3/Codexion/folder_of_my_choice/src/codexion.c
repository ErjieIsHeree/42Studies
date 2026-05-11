/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/11 20:23:07 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE ALL COMMENTS BEFORE EVALUATION
/**
 * ERRORS:
 * 	50: Args errors (get_rules)
 * 		101 Too few/many args (8 required, 9 if count program name)
 * 		110 Parsing errors
 * 		120 Validating errors
 * 
 * 	100: Initializating errors (codex_init)
 * 	150: Initializating errors (codex_start)
 * 	200: Initializating errors (codex_destroy)
 */

#include "codexion.h"

int	codexion(int argc, char **argv)
{
	t_codexion_bench	t_codexion_bench;
	int					error;

	error = get_rules(argc, argv, &(t_codexion_bench.rules));
	if (error != 0)
		return (error);
	error = codex_init(&t_codexion_bench);
	if (error != 0)
		return (error);
	error = codex_start(&t_codexion_bench);
	if (error != 0)
		return (error);
	error = codex_destroy(&t_codexion_bench);
	if (error != 0)
		return (error);
	return (0);
}
