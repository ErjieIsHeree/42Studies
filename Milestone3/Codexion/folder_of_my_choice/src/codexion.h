/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 22:32:15 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION
#define CODEXION

#include <unistd.h>

#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#include "codexion_types.h"

#include "parser/parser.h"
#include "coder/coder.h"

int	codexion(int argc, char **argv);
int	codex_init(t_sim *sim);
int	codex_run(t_sim *sim);
int	codex_destroy(t_sim *sim, t_error error, int delete_size);

#endif
