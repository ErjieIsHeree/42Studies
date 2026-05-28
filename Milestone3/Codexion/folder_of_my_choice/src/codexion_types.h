/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:01:00 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 11:38:11 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_TYPES_H
# define CODEXION_TYPES_H

# include <pthread.h>

typedef enum e_scheduler
{
	FIFO,
	EDF
}						t_scheduler;

typedef enum e_action
{
	COMPILE,
	DEBUG,
	REFACTOR
}						t_action;

typedef enum e_error
{
	PARSING_ERRORS = 60,
	PARSING_NUMBER_OF_CODERS_ERROR = 61,
	PARSING_TIME_TO_BURNOUT_ERROR = 62,
	PARSING_TIME_TO_COMPILE_ERROR = 63,
	PARSING_TIME_TO_DEBUG_ERROR = 64,
	PARSING_TIME_TO_REFACTOR_ERROR = 65,
	PARSING_COMPILES_REQUIRED_ERROR = 66,
	PARSING_DONGLE_COOLDOWN_ERROR = 67,
	PARSING_SCHEDULER_ERROR = 68,
	LOG_MUTEX_INIT_ERROR = 101,
	MALLOC_ERROR = 102,
	FINISHED_MUTEX_INIT_ERROR = 103,
	DONGLE_MUTEX_INIT_ERROR = 104,
	DONGLE_COND_INIT_ERROR = 105,
	QUEUE_MALLOC_ERROR = 106,
	QUEUE_MUTEX_INIT_ERROR = 107,
	CODER_MUTEX_INIT_ERROR = 108,
	THREAD_CREATION_ERROR = 151,
	MONITOR_CREATION_ERROR = 152,
	THREAD_JOINING_ERROR = 153,
	MONITOR_JOINING_ERROR = 154,
	YOU_STUPID_BRO = 255
}						t_error;

typedef struct s_sim	t_sim;
typedef struct s_coder	t_coder;
typedef struct s_dongle	t_dongle;

typedef struct s_coder
{
	pthread_t			coder_thread;
	int					id;
	pthread_mutex_t		coder_mutex;
	long				last_compile;
	int					compile_count;
	t_dongle			*left_dongle;
	t_dongle			*right_dongle;
	t_sim				*sim;
}						t_coder;

typedef struct s_dongle
{
	pthread_mutex_t		mutex;
	pthread_cond_t		cond;
	long				release_time;
	pthread_mutex_t		queue_mutex;
	t_coder				**queue;
	int					queue_size;
}						t_dongle;

typedef struct s_sim
{
	int					n_coders;
	long				time_to_burnout;
	long				time_to_compile;
	long				time_to_debug;
	long				time_to_refactor;
	int					compiles_required;
	long				dongle_cooldown;
	long				start_time;
	t_scheduler			scheduler;
	pthread_mutex_t		finished_mutex;
	int					finished;
	pthread_mutex_t		log_mutex;
	t_dongle			*dongles;
	t_coder				*coders;
}						t_sim;

#endif
