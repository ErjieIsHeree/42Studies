/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:01:00 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 22:32:04 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_TYPES
#define CODEXION_TYPES

#include <pthread.h>

typedef enum	e_scheduler
{
	FIFO,
	EDF
}	t_scheduler;

typedef enum	e_action
{
	COMPILE,
	DEBUG,
	REFACTOR
}	t_action;

typedef enum 	e_error
{
	LOG_MUTEX_INIT_ERROR = 101,
    MALLOC_ERROR = 102,
    MUTEX_INIT_ERROR = 103,
    COND_INIT_ERROR = 104,
	QUEUE_MALLOC_ERROR = 105,
	QUEUE_MUTEX_INIT_ERROR = 106,
	THREAD_CREATION_ERROR = 151,
    MONITOR_CREATION_ERROR = 152,
    THREAD_JOINING_ERROR = 153,
    MONITOR_JOINING_ERROR = 154,
	YOU_STUPID_BRO = 255
}	t_error;

typedef struct	s_sim t_sim;
typedef struct	s_coder t_coder;
typedef struct	s_dongle t_dongle;

typedef struct	s_coder
{
	pthread_t	coder_thread;
	int			id;
	long		last_compile;
	int			compile_count;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_sim		*sim;
}	t_coder;

typedef struct	s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	long			release_time;
	pthread_mutex_t	queue_mutex;
	t_coder			**queue;
	int				queue_size;
}	t_dongle;

typedef struct	s_sim
{
	int				n_coders;
	long			time_to_burnout;
	long			time_to_compile;
	long			time_to_debug;	
	long			time_to_refactor;
	int				compiles_required;
	long			dongle_cooldown;
	long			start_time;
	t_scheduler		scheduler;
	int				finished;
	pthread_mutex_t	log_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
}	t_sim;

#endif
