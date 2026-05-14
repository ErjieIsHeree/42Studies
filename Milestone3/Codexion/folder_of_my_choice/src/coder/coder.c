/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 18:44:25 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coder.h"

void	print_log(t_coder *coder, char *log)
{
	
	struct timeval	current_time;

	pthread_mutex_lock(&coder->sim->log_mutex);
	gettimeofday(&current_time, NULL);
	printf("%ld %d %s", current_time.tv_usec, coder->id, log);
	pthread_mutex_unlock(&coder->sim->log_mutex);
	return ;
}

void	drop_dongles(t_coder *coder)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	coder->left_dongle->release_time = now.tv_usec;
	coder->right_dongle->release_time = now.tv_usec;

	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_mutex_unlock(&coder->right_dongle->mutex);

	pthread_cond_broadcast(&coder->left_dongle->cond);
	pthread_cond_broadcast(&coder->right_dongle->cond);
}

void	action(t_coder *coder, t_action action)
{
	struct timeval	now;
	long			sleep_time;
	char			*action;

	if (action == COMPILE)
	{
		sleep_time = coder->sim->time_to_compile;
		action = "is compiling";
		coder->compile_count++;
		gettimeofday(&now, NULL);
		coder->last_compile = now.tv_usec;
	}
	else if (action == DEBUG)
	{
		sleep_time = coder->sim->time_to_debug;
		action = "is debugging";
	}
	else
	{
		sleep_time = coder->sim->time_to_refactor;
		action = "is refactoring";
	}
	print_log(coder, action);
	if (sleep_time)
		usleep(sleep_time);
}

void	*coder(void *arg)
{
	t_coder	*c;

	c = (t_coder *) arg;
	while (c->compile_count < c->sim->compiles_required && !c->sim->finished)
	{
		get_dongles(c);
		if (!c->sim->finished)
		{
			drop_dongles(c);
			break ;
		}
		action(c, COMPILE);
		drop_dongles(c);
		if (!c->sim->finished)
			break ;
		action(c, DEBUG);
		if (!c->sim->finished)
			break ;
		action(c, REFACTOR);
		if (!c->sim->finished)
			break ;
	}
	return (NULL);
}
