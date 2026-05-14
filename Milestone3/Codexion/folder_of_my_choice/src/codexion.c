/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 22:47:52 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE ALL COMMENTS BEFORE EVALUATION
/**
 * ERRORS:
 * 	50: Args errors (get_rules)
 * 		51 Too few/many args (8 required, 9 if count program name)
 * 		60 Parsing errors
 * 		70 Validating errors
 */

#include "codexion.h"

int	codexion(int argc, char **argv)
{
	t_sim	sim;
	int		error;

	error = parse_data(argc, argv, &sim);
	if (error != 0)
		return (error);
	error = codex_init(&sim);
	if (error != 0)
		return (error);
	error = codex_run(&sim);
	if (error != 0)
		return (error);
	codex_destroy(&sim);
	return (0);
}
