/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:06:32 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 22:50:08 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_TYPES
#define CODEXION_TYPES

#include "coder_types.h"

typedef struct s_sim
{
	int				n_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;
	long			time_to_refactor;
	int				compiles_required;
	long			dongle_cooldown;
	t_scheduler		scheduler;
	int				finished;
	pthread_mutex_t	log_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
}	t_sim;

typedef enum e_error
{
	MALLOC_ERROR = 101,
	LOG_MUTEX_CREATION_ERROR = 102,
	MUTEX_CREATION_ERROR = 103,
	COND_CREATION_ERROR = 104,
	THREAD_CREATION_ERROR = 105,
	MONITOR_CREATION_ERROR = 151,
	MONITOR_RUNNING_ERROR = 152,
	THREAD_RUNNING_ERROR = 153
}	t_error;

#endif
