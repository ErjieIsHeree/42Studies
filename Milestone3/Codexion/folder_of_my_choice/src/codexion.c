/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/15 22:50:29 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	print_sim(t_sim *sim)
{
	#include <stdio.h>
	printf("Number of coders: %d", sim->n_coders);
	printf("\nCompiles required: %d", sim->compiles_required);
	printf("\nTime to burnout: %ld", sim->time_to_burnout);
	printf("\nTime to compile: %ld", sim->time_to_compile);
	printf("\nTime to refactor: %ld", sim->time_to_refactor);
	printf("\nTime to debug: %ld", sim->time_to_debug);
	printf("\nDongle cd: %ld", sim->dongle_cooldown);
	printf("\nScheduler (0-fifo/1-edf): %d", sim->scheduler);
	printf("\nFinished (0-no/1-yes): %d", sim->finished);
	printf("\nSim start time: %ld", sim->start_time);

	printf("\nCoder id: %d", sim->coders->id);
	printf("\nCoder thread: %lu", sim->coders->coder_thread);
	printf("\nCoder compiles count: %d", sim->coders->compile_count);
	printf("\nCoder last compile: %ld", sim->coders->last_compile);
	printf("\nCoder left dongle: %p", sim->coders->left_dongle);
	printf("\nCoder right dongle: %p", sim->coders->right_dongle);
	printf("\nCoder simulator: %p", sim->coders->sim);

	printf("\nDongle queue: %p", sim->dongles->queue);
	printf("\nDongle queue size: %d", sim->dongles->queue_size);
	printf("\nDongle release time: %ld\n\n\n\n", sim->dongles->release_time);
}

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
	print_sim(&sim);
	if (error != 0)
		return (error);
	error = codex_run(&sim);
	if (error != 0)
		return (error);
	codex_destroy(&sim, 0, sim.n_coders);
	return (0);
}
