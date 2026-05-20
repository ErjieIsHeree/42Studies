/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:34:16 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 22:07:04 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int		is_alive(t_sim *sim, long last_compile)
{
	long			now_ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (now_ms - last_compile > sim->time_to_burnout && last_compile != 0)
		return (0);
	return (1);
}

void	*monitor(void *args)
{
	int				all_completed;
	int				i;
	t_sim			*sim;

	sim = (t_sim *)args;
	all_completed = 0;
	while (!all_completed && !sim->finished)
	{
		all_completed = 1;
		i = -1;
		while (++i < sim->n_coders && !sim->finished)
		{
			if (sim->coders[i].compile_count != sim->compiles_required)
			{
				all_completed = 0;
				if (!is_alive(sim, sim->coders[i].last_compile))
				{
					sim->finished = 1;
					usleep(3);
					print_log(&sim->coders[i], "burned out");
				}
			}
		}
	}
	return (NULL);
}

int	create_coders(t_sim *sim)
{
	int				i;
	long			now_ms;
	struct timeval	tv;

	i = -1;
	while (++i < sim->n_coders)
	{
		gettimeofday(&tv, NULL);
		now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		sim->coders[i].last_compile	= now_ms;
		if (pthread_create(&sim->coders[i].coder_thread, NULL, coder,
			&sim->coders[i]) != 0)
		{
			sim->finished = 1;
			return (i);
		}
	}
	return (0);
}

int	join_coders(t_sim *sim, int size)
{
	t_error	error;
	int		i;

	i = -1;
	error = 0;
	while (++i < size)
		if (pthread_join(sim->coders[i].coder_thread, NULL) != 0)
			error = THREAD_JOINING_ERROR;
	if(size == -1)
		return (MONITOR_CREATION_ERROR);
	if (size != sim->n_coders)
		return (THREAD_CREATION_ERROR);
	return (error);
}

int	codex_run(t_sim *sim)
{
	t_error			error;
	int				size;
	pthread_t		monitor_thread;

	size = create_coders(sim);
	if (size != 0)
		return (join_coders(sim, size));
	if (pthread_create(&monitor_thread, NULL, monitor, sim) != 0)
		return (join_coders(sim, -1));
	error = join_coders(sim, sim->n_coders);
	if (pthread_join(monitor_thread, NULL) != 0)
		error = MONITOR_JOINING_ERROR;
	return (error);
}
