/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 14:59:48 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION
#define CODEXION

#include <unistd.h>

#include <pthread.h>
#include <stdlib.h>     // malloc - free - atoi
#include <sys/time.h>   // gettimeofday
#include <string.h>     // strcmp - strlen - memset

#include "codexion_types.h"

#include "parser/parser.h"
#include "coder/coder.h"

int	codexion(int argc, char **argv);
int	codex_init(t_sim *sim);
int	codex_run(t_sim *sim);
int	codex_destroy(t_sim *sim, t_error error, int delete_size);

#endif
