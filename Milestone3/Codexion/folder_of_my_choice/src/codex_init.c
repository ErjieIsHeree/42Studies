/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:16:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 18:16:09 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	init_coders(t_sim *sim)
{
	int	i;
	int	last;

	last = sim->n_coders - 1;
	i = -1;
	while (++i < sim->n_coders)
	{
		if (pthread_mutex_init(&sim->coders[i].coder_mutex, NULL) != 0)
			return (codex_destroy(sim, CODER_MUTEX_INIT_ERROR, i));
		sim->coders[i].coder_thread = 0;
		sim->coders[i].id = i + 1;
		sim->coders[i].last_compile = 0;
		sim->coders[i].compile_count = 0;
		sim->coders[i].left_dongle = &sim->dongles[i];
		if (i == last)
			sim->coders[i].right_dongle = &sim->dongles[0];
		else
			sim->coders[i].right_dongle = &sim->dongles[i + 1];
		sim->coders[i].sim = sim;
	}
	return (0);
}

int	init_dongles(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_coders)
	{
		if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
			return (codex_destroy(sim, DONGLE_MUTEX_INIT_ERROR, i));
		if (pthread_cond_init(&sim->dongles[i].cond, NULL) != 0)
			return (codex_destroy(sim, DONGLE_COND_INIT_ERROR, i));
		sim->dongles[i].queue = malloc(sizeof(t_coder *) * 2);
		if (!sim->dongles[i].queue)
			return (codex_destroy(sim, QUEUE_MALLOC_ERROR, i));
		if (pthread_mutex_init(&sim->dongles[i].queue_mutex, NULL) != 0)
			return (codex_destroy(sim, QUEUE_MUTEX_INIT_ERROR, i));
		sim->dongles[i].queue_size = 0;
		sim->dongles[i].release_time = 0;
	}
	return (0);
}

int	init_sim(t_sim *sim)
{
	sim->start_time = 0;
	sim->finished = 0;
	if (pthread_mutex_init(&sim->log_mutex, NULL) != 0)
		return (codex_destroy(sim, LOG_MUTEX_INIT_ERROR, 0));
	sim->dongles = malloc(sizeof(t_dongle) * sim->n_coders);
	if (!sim->dongles)
		return (codex_destroy(sim, MALLOC_ERROR, 0));
	sim->coders = malloc(sizeof(t_coder) * sim->n_coders);
	if (!sim->dongles)
		return (codex_destroy(sim, MALLOC_ERROR, 0));
	if (pthread_mutex_init(&sim->finished_mutex, NULL) != 0)
		return (codex_destroy(sim, FINISHED_MUTEX_INIT_ERROR, 0));
	return (0);
}

int	codex_init(t_sim *sim)
{
	t_error	error;

	error = init_sim(sim);
	if (error != 0)
		return (error);
	error = init_dongles(sim);
	if (error != 0)
		return (error);
	error = init_coders(sim);
	if (error != 0)
		return (error);
	return (0);
}
