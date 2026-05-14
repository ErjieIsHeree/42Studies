/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_dongles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 21:33:31 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 18:10:38 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"
#include "heap/heap.h"

void	request_dongle(t_coder *coder, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	if (coder->sim->scheduler == FIFO)
		fifo_push_coder(coder, dongle);
	else
		edf_push_coder(coder, dongle);
	while (dongle->queue->id != coder->id)
		pthread_cond_wait(&dongle->cond,
			&dongle->mutex);
}

void	pop_request(t_dongle *r_dongle, t_dongle *l_dongle)
{
	pop_coder(r_dongle);
	pop_coder(l_dongle);
}

void	take_dongle(t_coder *coder, t_dongle *dongle)
{
	struct timeval	current_time;
	long			dongle_cd;

	gettimeofday(&current_time, NULL);
	dongle_cd = (coder->sim->dongle_cooldown - dongle->release_time -
		current_time.tv_usec);
	if (dongle_cd > 0 && !coder->sim->finished)
	{
		usleep(dongle_cd);
		gettimeofday(&current_time, NULL);
	}
	print_log(coder, "has taken a dongle");
}

void	get_dongles(t_coder	*c)
{
	if (c->id % 2 == 0)
	{
		request_dongle(c, c->right_dongle);
		take_dongle(c, c->right_dongle);
		request_dongle(c, c->left_dongle);
		take_dongle(c, c->left_dongle);
	}
	else
	{
		request_dongle(c, c->left_dongle);
		take_dongle(c, c->left_dongle);
		request_dongle(c, c->right_dongle);
		take_dongle(c, c->right_dongle);
	}
	pop_requests(c->right_dongle, c->left_dongle);
}
