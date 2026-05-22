/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 21:29:39 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER
#define CODER

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "heap/heap.h"
#include "../codexion_types.h"

void	*coder(void *arg);
void	*monitor(void *arg);

void	print_log(t_coder *coder, char *log);
void	get_dongles(t_coder	*c);
void	pop_requests(t_coder *coder);

#endif
