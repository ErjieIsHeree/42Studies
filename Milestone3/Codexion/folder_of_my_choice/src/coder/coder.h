/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 19:02:07 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODER
#define CODER

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#include "heap/heap.h"
#include "coder_types.h"

void	*coder(void *arg);
void	get_dongles(t_coder	*c);

#endif
