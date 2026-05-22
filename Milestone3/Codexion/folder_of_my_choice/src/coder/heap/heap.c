/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:06:50 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 21:33:16 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	fifo_push_coder(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->queue_mutex);
	if (dongle->queue_size == 0)
		dongle->queue[0] = coder;
	else
		dongle->queue[1] = coder;
	dongle->queue_size++;
	pthread_mutex_unlock(&dongle->queue_mutex);
}

void	edf_push_coder(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->queue_mutex);
	if (dongle->queue_size == 0)
		dongle->queue[0] = coder;
	else
	{
		if (coder->last_compile >= dongle->queue[0]->last_compile)
			dongle->queue[1] = coder;
		else
		{
			dongle->queue[1] = dongle->queue[0];
			dongle->queue[0] = coder;
		}
	}
	dongle->queue_size++;
	pthread_mutex_unlock(&dongle->queue_mutex);
}

void	pop_coder(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->queue_mutex);
	if (coder->id == dongle->queue[0]->id)
	{
		dongle->queue[0] = dongle->queue[1];
		dongle->queue[1] = NULL;
	}
	else
		dongle->queue[1] = NULL;
	dongle->queue_size--;
	pthread_mutex_unlock(&dongle->queue_mutex);
}
