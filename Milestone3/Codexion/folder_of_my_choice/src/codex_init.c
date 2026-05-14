/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:16:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 21:51:02 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_mutexes(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_coders)
		if (pthread_mutex_init(&sim->dongles[i].mutex, NULL) != 0)
			return (++i);
	return (0);
}

int	create_conds(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_coders)
		if (pthread_cond_init(&sim->dongles[i].cond, NULL) != 0)
			return (++i);
	return (0);
}

t_dongle	*get_right_dongle(t_sim *sim, int coder_id)
{
	if (coder_id == sim->n_coders - 1)
		return (sim->dongles);
	return (sim->dongles + coder_id + 1);
}

int	create_threads(t_sim *sim)
{
	int				i;
	struct timeval	now;

	gettimeofday(&now, NULL);
	i = -1;
	while (++i < sim->n_coders)
	{
		sim->coders[i] = (t_coder){
			.id				= i,
			.last_compile	= now.tv_usec,
			.compile_count	= 0,
			.left_dongle	= sim->dongles + i,
			.right_dongle	= get_right_dongle(sim, i),
			.sim			= sim
		};
		if (pthread_create(&sim->coders[i].coder_thread, NULL, coder,
			&sim->coders[i]) != 0)
			return (++i);
	}
	return (0);
}

int	codex_init(t_sim *sim)
{
	int	size;

	sim->finished = 0;
	sim->coders = malloc(sizeof(t_coder) * sim->n_coders);
	if (!sim->coders)
		return (creation_error(sim, MALLOC_ERROR, 0));
	sim->dongles = malloc(sizeof(t_coder) * sim->n_coders);
	if (!sim->dongles)
		return (creation_error(sim, MALLOC_ERROR, 0));
	if (pthread_mutex_init(&sim->log_mutex, NULL) != 0)
		return (creation_error(sim, LOG_MUTEX_CREATION_ERROR, 0));
	size = create_mutexes(&sim);
	if (size != 0)
		return (creation_error(sim, MUTEX_CREATION_ERROR, size));
	size = create_conds(&sim);
	if (size != 0)
		return (creation_error(sim, COND_CREATION_ERROR, size));
	size = create_threads(&sim);
	if (size != 0)
		return (creation_error(sim, THREAD_CREATION_ERROR, size));
	return (0);
}
