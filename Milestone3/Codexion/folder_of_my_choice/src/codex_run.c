/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:34:16 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 22:27:08 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	codex_run(t_sim *sim)
{
	int			i;
	t_error		error;
	pthread_t	monitor;

	error = 0;
	if (pthread_create(monitor, NULL, monitor, sim) != 0)
		error = MONITOR_CREATION_ERROR;
	if (!error && pthread_join(monitor, NULL) != 0)
		error = MONITOR_RUNNING_ERROR;
	if (error)
		sim->finished = 1;
	i = -1;
	while (++i < sim->n_coders)
	{
		if (pthread_join(sim->coders->coder_thread, NULL) != 0)
		{
			sim->finished = 1;
			error = THREAD_RUNNING_ERROR;
		}
	}
	return (error);
}

