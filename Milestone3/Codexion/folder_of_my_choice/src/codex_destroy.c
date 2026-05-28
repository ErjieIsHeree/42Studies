/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 11:38:05 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_coders(t_sim *sim, t_error error, int delete_size)
{
	int	i;

	i = -1;
	while (++i < delete_size)
		pthread_mutex_destroy(&sim->coders[i].coder_mutex);
	if (error > CODER_MUTEX_INIT_ERROR)
		pthread_mutex_destroy(&sim->coders[i].coder_mutex);
}

void	destroy_dongles(t_sim *sim, t_error error, int delete_size)
{
	int	i;

	i = -1;
	while (++i < delete_size)
	{
		pthread_mutex_destroy(&sim->dongles[i].mutex);
		pthread_cond_destroy(&sim->dongles[i].cond);
		free(sim->dongles[i].queue);
		pthread_mutex_destroy(&sim->dongles[i].queue_mutex);
	}
	if (error > DONGLE_MUTEX_INIT_ERROR)
		pthread_mutex_destroy(&sim->dongles[i].mutex);
	if (error > DONGLE_COND_INIT_ERROR)
		pthread_cond_destroy(&sim->dongles[i].cond);
	if (error > QUEUE_MALLOC_ERROR)
		free(sim->dongles[i].queue);
}

void	destroy_sim(t_sim *sim, t_error error)
{
	if (sim->coders)
		free(sim->coders);
	if (sim->dongles)
		free(sim->dongles);
	if (error != FINISHED_MUTEX_INIT_ERROR)
		pthread_mutex_destroy(&sim->finished_mutex);
}

int	codex_destroy(t_sim *sim, t_error error, int delete_size)
{
	if (error == CODER_MUTEX_INIT_ERROR)
		destroy_coders(sim, error, delete_size);
	else if (error > CODER_MUTEX_INIT_ERROR)
		destroy_coders(sim, 0, sim->n_coders);
	if (error >= DONGLE_MUTEX_INIT_ERROR && error <= QUEUE_MUTEX_INIT_ERROR)
		destroy_dongles(sim, error, delete_size);
	else if (error > QUEUE_MUTEX_INIT_ERROR)
		destroy_dongles(sim, 0, sim->n_coders);
	if (error >= MALLOC_ERROR && error <= FINISHED_MUTEX_INIT_ERROR)
		destroy_sim(sim, error);
	else if (error > FINISHED_MUTEX_INIT_ERROR)
		destroy_sim(sim, 0);
	return (error);
}
