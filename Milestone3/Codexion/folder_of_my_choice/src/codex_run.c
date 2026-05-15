/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:34:16 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/15 22:56:42 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_threads(t_sim *sim)
{
	int				i;
	struct timeval	now;

	gettimeofday(&now, NULL);
	sim->start_time = now.tv_usec;
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

int	codex_run(t_sim *sim)  //  TODO remake this cleaner and better, take in mind new init values
{
	int			i;
	t_error		error;
	pthread_t	monitor_thread;

	i = create_threads(sim);
	if (i != 0)
		return (creation_error(sim, THREAD_CREATION_ERROR, i));
	error = 0;
	if (pthread_create(&monitor_thread, NULL, monitor, (void *)sim) != 0)
		error = MONITOR_CREATION_ERROR;
	i = -1;
	while (++i < sim->n_coders)
	{
		if (pthread_join(sim->coders[i].coder_thread, NULL) != 0)
		{
			sim->finished = 1;
			error = THREAD_RUNNING_ERROR;
		}
	}
	if (!error && pthread_join(monitor_thread, NULL) != 0)
		error = MONITOR_RUNNING_ERROR;
	if (error)
		sim->finished = 1;
	return (error);
}

