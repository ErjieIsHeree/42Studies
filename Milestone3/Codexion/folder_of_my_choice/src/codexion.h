/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 19:40:53 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION
#define CODEXION

#include <pthread.h>    // threads
#include <stdlib.h>     // malloc - free - atoi
#include <sys/time.h>   // gettimeofday
#include <unistd.h>     // write - usleep
#include <stdio.h>      // printf - fprintf
#include <string.h>     // strcmp - strlen - memset

#include "rules/rules.h"
#include "coder/codex.h"

typedef struct s_table
{
	pthread_t		*coder;
	pthread_mutex_t	*dongle;
	pthread_cond_t	*dongle_cond;
}	t_table;

int	codexion(int argc, char **argv);
int	codex_init(t_rules *rules, t_table *table);
int	codex_start(t_rules *rules, t_table *table);
int	codex_destroy(t_rules *rules, t_table *table, int init_error);

#endif
