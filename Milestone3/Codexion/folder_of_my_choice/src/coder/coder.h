/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/27 12:54:44 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER_H
# define CODER_H

# include "../codexion_types.h"
# include "heap/heap.h"
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

void	*coder(void *arg);
void	*monitor(void *arg);

void	print_log(t_coder *coder, char *log);
void	get_dongles(t_coder *c);
void	pop_requests(t_coder *coder);

#endif
