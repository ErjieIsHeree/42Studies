/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:34:16 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 18:16:48 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_alive(t_sim *sim, long last_compile)
{
	if (last_compile != 0 && get_time() - last_compile > sim->time_to_burnout)
		return (0);
	return (1);
}

void	*monitor(void *args)
{
	int		all_completed;
	int		i;
	t_sim	*sim;

	sim = (t_sim *)args;
	all_completed = 0;
	while (!all_completed && !get_finished(sim))
	{
		all_completed = 1;
		i = -1;
		while (++i < sim->n_coders && !get_finished(sim))
		{
			if (get_compile_count(&sim->coders[i]) != sim->compiles_required)
			{
				all_completed = 0;
				if (!is_alive(sim, get_last_compile(&sim->coders[i])))
					print_log(&sim->coders[i], "burned out");
			}
		}
	}
	return (NULL);
}

int	create_coders(t_sim *sim)
{
	int				i;

	i = -1;
	while (++i < sim->n_coders)
	{
		set_last_compile(&sim->coders[i], get_time());
		if (pthread_create(&sim->coders[i].coder_thread, NULL, coder,
				&sim->coders[i]) != 0)
		{
			set_finished(sim, 1);
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
	if (size == -1)
		return (MONITOR_CREATION_ERROR);
	if (size != sim->n_coders)
		return (THREAD_CREATION_ERROR);
	return (error);
}

int	codex_run(t_sim *sim)
{
	t_error		error;
	int			size;
	pthread_t	monitor_thread;

	size = create_coders(sim);
	if (size != 0)
		return (join_coders(sim, size));
	if (pthread_create(&monitor_thread, NULL, monitor, sim) != 0)
		return (join_coders(sim, -1));
	error = join_coders(sim, sim->n_coders);
	if (pthread_join(monitor_thread, NULL) != 0)
		error = MONITOR_JOINING_ERROR;
	if (sim->n_coders == 1)
		return (YOU_STUPID_BRO);
	return (error);
}
