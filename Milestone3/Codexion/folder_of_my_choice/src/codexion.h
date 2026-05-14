/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 11:10:35 by erjieishere      ###   ########.fr       */
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
#include "coder/coder.h"

typedef struct s_codexion_bench
{
	t_rules	rules;
}	t_codexion_bench;

int	codexion(int argc, char **argv);

int	codex_init(t_codexion_bench *codexion_data);
int	codex_start(t_codexion_bench *codexion_data);
int	codex_destroy(t_codexion_bench *codexion_data);

#endif
