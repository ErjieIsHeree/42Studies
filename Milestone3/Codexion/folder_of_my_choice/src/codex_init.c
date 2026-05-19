/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:16:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/19 23:18:36 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_coders(t_sim *sim)
{
	int	i;
	int	last;

	last = sim->n_coders - 1;
	i = -1;
	while (++i < sim->n_coders)
	{
		sim->coders[i].coder_thread = 0;
		sim->coders[i].id = i;
		sim->coders[i].last_compile = 0;
		sim->coders[i].compile_count = 0;
		sim->coders[i].left_dongle = &sim->dongles[i];
		if (i == last)
			sim->coders[i].right_dongle = &sim->dongles[0];
		else
			sim->coders[i].right_dongle = &sim->dongles[i + 1];
		sim->coders[i].sim = sim;
	}
}

int		init_dongles(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_coders)
	{
		if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
			return (codex_destroy(sim, MUTEX_INIT_ERROR, i)); 
		if (pthread_cond_init(&sim->dongles[i].cond, NULL) != 0)
			return (codex_destroy(sim, COND_INIT_ERROR, i)); 
		sim->dongles[i].queue = malloc(sizeof(t_coder *));
		if (!sim->dongles[i].queue)
			return (codex_destroy(sim, QUEUE_MALLOC_ERROR, i)); 
		sim->dongles[i].queue_size = i + 1;
		sim->dongles[i].release_time = 0;
	}
	return (0);
}

int		init_sim(t_sim *sim)
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
	return (0);
}

int		codex_init(t_sim *sim)
{
	t_error error;

	error = init_sim(sim);
	if (error != 0)
		return (error);
	error = init_dongles(sim);
	if (error != 0)
		return (error);
	init_coders(sim);
	return (0);
}
