/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:11:05 by exia              #+#    #+#             */
/*   Updated: 2026/05/27 13:22:05 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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

