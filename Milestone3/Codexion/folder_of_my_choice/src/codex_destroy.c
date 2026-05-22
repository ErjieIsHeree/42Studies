/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 22:20:41 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destroy_dongles(t_sim *sim, t_error error, int delete_size)
{
	int	i;

	i = -1;
	if (error != 0)
		delete_size--;
	while (++i < delete_size)
	{
		pthread_mutex_destroy(&sim->dongles[i].mutex);
		pthread_cond_destroy(&sim->dongles[i].cond);
		free(sim->dongles[i].queue);
		pthread_mutex_destroy(&sim->dongles[i].queue_mutex);
	}
	if (error == COND_INIT_ERROR)
		pthread_mutex_destroy(&sim->dongles[i].mutex);
	else if (error == QUEUE_MALLOC_ERROR)
	{
		pthread_mutex_destroy(&sim->dongles[i].mutex);
		pthread_cond_destroy(&sim->dongles[i].cond);
	}
	else if (error != 0)
	{
		pthread_mutex_destroy(&sim->dongles[i].mutex);
		pthread_cond_destroy(&sim->dongles[i].cond);
		free(sim->dongles[i].queue);
	}
}

void	destroy_sim(t_sim *sim, t_error error)
{
	if (error == LOG_MUTEX_INIT_ERROR)
		return ;
	pthread_mutex_destroy(&sim->log_mutex);
	if (sim->coders)
		free(sim->coders);
	if (sim->dongles)
		free(sim->dongles);
	return ;
}

int		codex_destroy(t_sim *sim, t_error error, int delete_size)
{
	if (error != MALLOC_ERROR && error != LOG_MUTEX_INIT_ERROR)
		destroy_dongles(sim, error, delete_size);
	if (error > QUEUE_MUTEX_INIT_ERROR)
		pthread_mutex_destroy(&sim->dongles[sim->n_coders - 1].queue_mutex);
	destroy_sim(sim, error);
	return (error);
}
