/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 22:13:39 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

void	print_log(t_coder *coder, char *log)
{
	struct timeval	tv;
	long			now_ms;

	pthread_mutex_lock(&coder->sim->log_mutex);
	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	if (!coder->sim->start_time)
		coder->sim->start_time = now_ms;
	printf("%ld %d %s\n", now_ms - coder->sim->start_time,
		coder->id, log);
	pthread_mutex_unlock(&coder->sim->log_mutex);
	return ;
}

void	drop_dongles(t_coder *coder)
{
	long			now_ms;
	struct timeval	tv;

	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	gettimeofday(&tv, NULL);
	now_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	coder->left_dongle->release_time = now_ms;
	coder->right_dongle->release_time = now_ms;
	pop_requests(coder);
	pthread_cond_broadcast(&coder->left_dongle->cond);
	pthread_cond_broadcast(&coder->right_dongle->cond);
}

void	compile(t_coder *coder)
{
	long			now_ms;
	struct timeval	tv;

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
}

void	*coder(void *arg)
{
	t_coder	*c;
	char	a;

	c = (t_coder *) arg;
	a = '0' + c->id;
	while (c->compile_count < c->sim->compiles_required && !c->sim->finished)
	{
		get_dongles(c);
		if (c->sim->finished)
		{
			drop_dongles(c);
			break ;
		}
		action(c, COMPILE);
		drop_dongles(c);
		if (c->sim->finished)
			break ;
		action(c, DEBUG);
		if (c->sim->finished)
			break ;
		action(c, REFACTOR);
		if (c->sim->finished)
			break ;
	}
	write(1, &a, 1);
	write(1, "\n", 1);
	return (NULL);
}
