/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/27 14:56:01 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (codex_destroy(&sim, error, sim.n_coders));
	codex_destroy(&sim, 0, sim.n_coders);
	return (0);
}
