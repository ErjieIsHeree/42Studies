/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 20:01:40 by erjieishere      ###   ########.fr       */
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
	return ;
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
	int	i;

	i = -1;
	while (++i < sim->n_coders)
		pthread_mutex_destroy(&sim->dongles[i].queue_mutex);
	if (error != MALLOC_ERROR && error != LOG_MUTEX_INIT_ERROR)
		destroy_dongles(sim, error, delete_size);
	destroy_sim(sim, error);
	return (error);
}
