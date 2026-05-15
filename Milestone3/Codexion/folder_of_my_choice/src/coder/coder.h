/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 23:17:04 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER
#define CODER

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#include "heap/heap.h"
#include "../codexion_types.h"

void	*coder(void *arg);
void	*monitor(void *arg);

void	print_log(t_coder *coder, char *log, long sleep);
void	get_dongles(t_coder	*c);

#endif
