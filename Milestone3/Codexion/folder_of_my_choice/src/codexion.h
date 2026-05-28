/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:33:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 11:38:15 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include "coder/coder.h"
# include "codexion_types.h"
# include "parser/parser.h"
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

long	get_time(void);

int	codexion(int argc, char **argv);
int	codex_init(t_sim *sim);
int	codex_run(t_sim *sim);
int	codex_destroy(t_sim *sim, t_error error, int delete_size);

void	set_finished(t_sim *sim, long new_value);
long	get_finished(t_sim *sim);

void	set_last_compile(t_coder *coder, long value);
long	get_last_compile(t_coder *coder);
void	add_compile_count(t_coder *coder);
long	get_compile_count(t_coder *coder);

t_coder	*get_first_coder(pthread_mutex_t *queue_mutex, t_coder **queue);

#endif
