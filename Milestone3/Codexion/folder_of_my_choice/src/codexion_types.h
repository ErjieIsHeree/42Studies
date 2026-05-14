/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:01:00 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 23:08:49 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// codexion_types.h - UN SOLO ARCHIVO con todo en orden
#ifndef CODEXION_TYPES
#define CODEXION_TYPES
#include <pthread.h>

// 1. enums primero (no dependen de nadie)
typedef enum e_scheduler { FIFO, EDF }           t_scheduler;
typedef enum e_action    { COMPILE, DEBUG, REFACTOR } t_action;
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
}   t_error;

// 2. forward declarations
typedef struct s_sim    t_sim;
typedef struct s_coder  t_coder;
typedef struct s_dongle t_dongle;

// 3. structs en cualquier orden porque todos usan punteros
typedef struct s_coder
{
    pthread_t   coder_thread;
    int         id;
    long        last_compile;
    int         compile_count;
    t_dongle    *left_dongle;
    t_dongle    *right_dongle;
    t_sim       *sim;
}   t_coder;

typedef struct s_dongle
{
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
    long            release_time;
    t_coder         queue[2];
    int             queue_size;
}   t_dongle;

typedef struct s_sim
{
    int             n_coders;
    long            time_to_burnout;
    long            time_to_compile;
    long            time_to_debug;
    long            time_to_refactor;
    int             compiles_required;
    long            dongle_cooldown;
    t_scheduler     scheduler;
    int             finished;
    pthread_mutex_t log_mutex;
    t_dongle        *dongles;
    t_coder         *coders;
}   t_sim;

#endif