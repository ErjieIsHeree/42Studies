/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:22:46 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 22:49:03 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_TYPES
#define CODER_TYPES

#include <pthread.h>
#include "codexion_types.h"

typedef enum e_scheduler
{
	FIFO,
	EDF
}	t_scheduler;

typedef enum e_action
{
	COMPILE,
	DEBUG,
	REFACTOR
}	t_action;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	long			release_time;  // cuándo fue soltado (para cooldown)
	t_coder			queue[2];         // FIFO o EDF - quién está esperando
	int				queue_size;
}	t_dongle;

typedef struct s_coder
{
	pthread_t	coder_thread;
	int			id;
	long		last_compile;  // para calcular burnout (inicio de simulacion si no ha hecho ningun compile aun)
	int			compile_count;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_sim		*sim;
}	t_coder;

#endif
