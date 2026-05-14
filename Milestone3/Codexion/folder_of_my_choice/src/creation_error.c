/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:26:03 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 21:48:05 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_sim(t_sim *sim, int mutexes, int conds, int threads)
{
	int i;

	sim->finished = 1;
	i = -1;
	while (++i < threads)
		pthread_join(sim->coders[i].coder_thread, NULL);
	i = -1;
	while (++i < conds)
		pthread_cond_destroy(&sim->dongles[i].cond);
	i = -1;
	while (++i < mutexes)
		pthread_mutex_destroy(&sim->dongles[i].mutex);
	return ;
}

int	creation_error(t_sim *sim, t_error error, int size)
{
	if (error == LOG_MUTEX_CREATION_ERROR)
		pthread_mutex_destroy(&sim->log_mutex);
	else if (error == MUTEX_CREATION_ERROR)
		destroy_sim(sim, size, 0, 0);
	else if (error == COND_CREATION_ERROR)
		destroy_sim(sim, sim->n_coders, size, 0);
	else if (error == THREAD_CREATION_ERROR)
		destroy_sim(sim, sim->n_coders, sim->n_coders, size);
	if (sim->coders)
		free(sim->coders);
	if (sim->dongles)
		free(sim->dongles);
	return (error);
}
