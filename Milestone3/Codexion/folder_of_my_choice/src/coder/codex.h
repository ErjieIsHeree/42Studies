/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 17:59:15 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEX
#define CODEX

#include <pthread.h>    // threads
#include <sys/time.h>   // gettimeofday
#include <unistd.h>     // write - usleep

#include "../rules/rules.h"

typedef struct s_table
{
	pthread_t		*coders;
	pthread_mutex_t	*dongles;
	pthread_cond_t	*coder_conds;
}	t_table;

void	*coder(void *arg);

int		codex_start(t_rules *rules, t_table *table);

#endif
