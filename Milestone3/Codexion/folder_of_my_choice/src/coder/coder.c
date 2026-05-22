/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 22:24:57 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

void	print_log(t_coder *coder, char *log)
{
	struct timeval	tv;
	long			now_ms;

	if (coder->sim->finished)
		return ;
	pthread_mutex_lock(&coder->sim->log_mutex);
	if (!strcmp(log, "burned out"))
		coder->sim->finished = 1;
	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (!coder->sim->start_time)
		coder->sim->start_time = now_ms;
	printf("%ld %d %s\n", now_ms - coder->sim->start_time, coder->id, log);
	pthread_mutex_unlock(&coder->sim->log_mutex);
	return ;
}

void	drop_dongles(t_coder *coder)
{
	long			now_ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	coder->left_dongle->release_time = now_ms;
	coder->right_dongle->release_time = now_ms;
	pop_requests(coder);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_cond_broadcast(&coder->left_dongle->cond);
	pthread_cond_broadcast(&coder->right_dongle->cond);
}

void	compile(t_coder *coder)
{
	long			now_ms;
	struct timeval	tv;

	get_dongles(coder);
	coder->compile_count++;
	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	coder->last_compile = now_ms;
}

void	action(t_coder *coder, t_action action)
{
	long			sleep_time;
	char			*s_action;

	if (action == COMPILE)
	{
		sleep_time = coder->sim->time_to_compile;
		s_action = "is compiling";
		compile(coder);
	}
	else if (action == DEBUG)
	{
		sleep_time = coder->sim->time_to_debug;
		s_action = "is debugging";
	}
	else if (action == REFACTOR)
	{
		sleep_time = coder->sim->time_to_refactor;
		s_action = "is refactoring";
	}
	print_log(coder, s_action);
	if (sleep_time)
		usleep(sleep_time * 1000);
	if (action == COMPILE)
		drop_dongles(coder);
}

void	*coder(void *arg)
{
	struct timeval	tv;
	t_coder			*c;

	c = (t_coder *) arg;
	if (c->sim->n_coders == 1)
	{
		gettimeofday(&tv, NULL);
		c->sim->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		usleep((c->sim->time_to_burnout) * 1000);
		return (NULL);
	}
	while (c->compile_count < c->sim->compiles_required && !c->sim->finished)
	{
		action(c, COMPILE);
		if (c->sim->finished)
			break ;
		action(c, DEBUG);
		if (c->sim->finished)
			break ;
		action(c, REFACTOR);
		if (c->sim->finished)
			break ;
	}
	return (NULL);
}
