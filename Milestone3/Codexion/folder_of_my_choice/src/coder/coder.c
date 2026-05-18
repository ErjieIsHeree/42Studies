/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/16 20:12:42 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

void	print_log(t_coder *coder, char *log, long sleep)
{
	struct timeval	current_time;

	if (sleep)
		usleep(sleep);  // TODO revisar a ver si imprime 10000 microsec despues o mas
	pthread_mutex_lock(&coder->sim->log_mutex);
	gettimeofday(&current_time, NULL);
	printf("%ld %d %s\n", current_time.tv_usec - coder->sim->start_time,
		coder->id, log);
	pthread_mutex_unlock(&coder->sim->log_mutex);
	return ;
}

void	drop_dongles(t_coder *coder)
{
	struct timeval now;

	pthread_mutex_unlock(&coder->left_dongle->mutex);
	gettimeofday(&now, NULL);
	coder->left_dongle->release_time = now.tv_usec;
	pthread_cond_broadcast(&coder->left_dongle->cond);

	pthread_mutex_unlock(&coder->right_dongle->mutex);
	gettimeofday(&now, NULL);
	coder->right_dongle->release_time = now.tv_usec;
	pthread_cond_broadcast(&coder->right_dongle->cond);
}

void	action(t_coder *coder, t_action action)
{
	struct timeval	now;
	long			sleep_time;
	char			*s_action;

	if (action == COMPILE)
	{
		sleep_time = coder->sim->time_to_compile;
		s_action = "is compiling";
		coder->compile_count++;
		gettimeofday(&now, NULL);
		coder->last_compile = now.tv_usec;
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
	print_log(coder, s_action, 0);
	if (sleep_time)
		usleep(sleep_time);
}

void	*coder(void *arg)
{
	t_coder	*c;

	c = (t_coder *) arg;  // TODO encuentra todos los errores (ronda entre no incializacion de alguna variable y codex_run)
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
	return (NULL);
}
