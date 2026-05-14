/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 23:01:51 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION
#define CODEXION

#include <pthread.h>
#include <stdlib.h>     // malloc - free - atoi
#include <sys/time.h>   // gettimeofday
#include <string.h>     // strcmp - strlen - memset

#include "codexion_types.h"

#include "parser/parser.h"
#include "coder/coder.h"

int	codexion(int argc, char **argv);

int		codex_init(t_sim *sim);
int		creation_error(t_sim *sim, t_error error, int size);

int		codex_run(t_sim *sim);
void	codex_destroy(t_sim *sim);

#endif
