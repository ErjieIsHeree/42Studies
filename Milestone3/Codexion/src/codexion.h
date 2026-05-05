/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/06 00:09:56 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! Delete comments before finish and delete this one after check they are

#ifndef CODEXION
#define CODEXION

#include <pthread.h>    // threads
#include <sys/time.h>   // gettimeofday
#include <unistd.h>     // write - usleep

#include "rules/rules.h"

typedef struct s_table
{
	pthread_t		coders[2147483647];
	pthread_mutex_t	dongles[2147483647];
	pthread_cond_t	coder_conds[2147483647];
}	t_table;

// TODO Codexion
int	codexion(int argc, char **argv);
int	codex_init(t_rules *codex_rules, t_table *table);
int	codex_start(t_rules *codex_rules, t_table *table);
int	codex_destroy(t_table *table);


#endif
