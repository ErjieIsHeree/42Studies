/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:11:05 by exia              #+#    #+#             */
/*   Updated: 2026/05/28 11:38:20 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	set_finished(t_sim *sim, long new_value)
{
	pthread_mutex_lock(&sim->finished_mutex);
	sim->finished = new_value;
	pthread_mutex_unlock(&sim->finished_mutex);
}

long	get_finished(t_sim *sim)
{
	long	val;

	pthread_mutex_lock(&sim->finished_mutex);
	val = sim->finished;
	pthread_mutex_unlock(&sim->finished_mutex);
	return (val);
}

