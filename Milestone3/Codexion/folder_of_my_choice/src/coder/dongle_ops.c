/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:33:31 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/27 13:24:04 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "heap/heap.h"
#include "../codexion.h"

int	wait_cooldown(long req_cd, t_dongle *dongle)
{
	struct timeval	tv;
	long			cd_left;
	long			now;

	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	cd_left = req_cd + dongle->release_time - now;
	if (cd_left > 0)
	{
		usleep(cd_left);
		return (1);
	}
	return (0);
}


void	request_dongle_mutex(t_coder *coder, t_dongle *dongle)
{
	if (coder->sim->scheduler == FIFO)
		fifo_push_coder(coder, dongle);
	else
		edf_push_coder(coder, dongle);
	pthread_mutex_lock(&dongle->mutex);
	while (get_first_coder(&dongle->queue_mutex, dongle->queue)->id
		!= coder->id)
	{
		pthread_cond_wait(&dongle->cond, &dongle->mutex);
		if (wait_cooldown(coder->sim->dongle_cooldown, dongle))
		{
			pthread_mutex_unlock(&dongle->mutex);
			pthread_cond_broadcast(&dongle->cond);
		}
	}
	print_log(coder, "has taken a dongle");
}

void	pop_requests(t_coder *coder)
{
	pop_coder(coder, coder->right_dongle);
	pop_coder(coder, coder->left_dongle);
}

void	get_dongles(t_coder *c)
{
	if (c->id % 2 == 0)
	{
		request_dongle_mutex(c, c->right_dongle);
		request_dongle_mutex(c, c->left_dongle);
	}
	else
	{
		request_dongle_mutex(c, c->left_dongle);
		request_dongle_mutex(c, c->right_dongle);
	}
}
