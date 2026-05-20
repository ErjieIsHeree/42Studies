/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:33:31 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 22:23:46 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "heap/heap.h"

void	request_dongle_mutex(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->queue_mutex);
	if (coder->sim->scheduler == FIFO)
		fifo_push_coder(coder, dongle);
	else
		edf_push_coder(coder, dongle);
	pthread_mutex_unlock(&dongle->queue_mutex);
	pthread_mutex_lock(&dongle->mutex);
	while (dongle->queue[0]->id != coder->id)  // !! IT NEVER LEAVES THIS WHEN SOMEONE BURNS OUT
		pthread_cond_wait(&dongle->cond,
			&dongle->mutex);
}

void	pop_requests(t_coder *coder)
{
	pthread_mutex_lock(&coder->right_dongle->queue_mutex);
	pop_coder(coder->right_dongle);
	pthread_mutex_unlock(&coder->right_dongle->queue_mutex);
	pthread_mutex_lock(&coder->left_dongle->queue_mutex);
	pop_coder(coder->left_dongle);
	pthread_mutex_unlock(&coder->left_dongle->queue_mutex);
}

void	take_dongle(t_coder *coder, t_dongle *dongle)
{
	struct timeval	tv;
	long			now_ms;
	long			dongle_cd;

	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	dongle_cd = (coder->sim->dongle_cooldown - now_ms + dongle->release_time);
	if (dongle_cd > 0 && !coder->sim->finished)
		usleep(dongle_cd * 1000);
	if (!coder->sim->finished)
		print_log(coder, "has taken a dongle");
}

void	get_dongles(t_coder	*c)
{
	if (c->id % 2 == 0)
	{
		request_dongle_mutex(c, c->right_dongle);
		take_dongle(c, c->right_dongle);
		request_dongle_mutex(c, c->left_dongle);
		take_dongle(c, c->left_dongle);
	}
	else
	{
		request_dongle_mutex(c, c->left_dongle);
		take_dongle(c, c->left_dongle);
		request_dongle_mutex(c, c->right_dongle);
		take_dongle(c, c->right_dongle);
	}
}
