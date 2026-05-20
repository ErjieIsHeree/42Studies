/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 16:36:59 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/**
 * ERRORS:
 * 	50: Args errors (get_rules)
 * 		51 Too few/many args (8 required, 9 if count program name)
 * 		60 Parsing errors
 * 		70 Validating errors
 */
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
		return (codex_destroy(&sim, error, sim.n_coders));
	codex_destroy(&sim, 0, sim.n_coders);
	return (0);
}
