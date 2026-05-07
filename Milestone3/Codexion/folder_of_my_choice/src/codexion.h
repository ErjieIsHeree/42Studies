/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 17:54:53 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION
#define CODEXION

#include <pthread.h>

#include "rules/rules.h"
#include "coder/codex.h"

int	codexion(int argc, char **argv);
int	codex_init(t_rules *rules, t_table *table);
int	codex_destroy(t_rules *rules, t_table *table, int init_error);

#endif
