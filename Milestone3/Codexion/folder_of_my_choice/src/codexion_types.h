/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:01:00 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/16 18:31:07 by erjieishere      ###   ########.fr       */
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
	THREAD_CREATION_ERROR = 151,
    MONITOR_CREATION_ERROR = 152,
    THREAD_JOINING_ERROR = 153,
    MONITOR_JOINING_ERROR = 154
}	t_error;

typedef struct	s_sim t_sim;
typedef struct	s_coder t_coder;
typedef struct	s_dongle t_dongle;

typedef struct	s_coder
{
	pthread_t	coder_thread;	// 0
	int			id;				// its corresponding id 1 - n
	long		last_compile;	// 0
	int			compile_count;	// 0
	t_dongle	*left_dongle;	// left dongle ptr
	t_dongle	*right_dongle;	// right dongle ptr
	t_sim		*sim;			// sim ptr
}	t_coder;

typedef struct	s_dongle
{
	pthread_mutex_t	mutex;			// init_mute
	pthread_cond_t	cond;			// init_cond
	long			release_time;	// 0
	t_coder			**queue;		// ptr of ptr
	int				queue_size;		// 0
}	t_dongle;

typedef struct	s_sim
{
	int				n_coders;			// introduced int
	long			time_to_burnout;	// introduced int
	long			time_to_compile;	// introduced int
	long			time_to_debug;		// introduced int
	long			time_to_refactor;	// introduced int
	int				compiles_required;	// introduced int
	long			dongle_cooldown;	// introduced int
	long			start_time;			// 0
	t_scheduler		scheduler;			// 0 fifo - 1 edf
	int				finished;			// 0
	pthread_mutex_t	log_mutex;			// init_mutex
	t_dongle		*dongles;			// dongles ptr
	t_coder			*coders;			// coders ptr
}	t_sim;

#endif
