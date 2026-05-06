/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/06 01:12:02 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! Delete comments before finish and delete this one after check they are

#ifndef CODEXION
#define CODEXION

#include <pthread.h>    // threads
#include <sys/time.h>   // gettimeofday
#include <unistd.h>     // write - usleep
#include <limits.h>

#include "rules/rules.h"

typedef struct s_table
{
	pthread_t		coders[INT_MAX];
	pthread_mutex_t	dongles[INT_MAX];
	pthread_cond_t	coder_conds[INT_MAX];
}	t_table;

// TODO Codexion
int	codexion(int argc, char **argv);

int	codex_init(t_rules *rules, t_table *table);
int	init_error_parse(int init_return);

int	codex_start(t_rules *rules, t_table *table);

int	codex_destroy(t_rules *rules, t_table *table, int init_error);

#endif
