/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:07:53 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 19:39:49 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEX
#define CODEX

#include <pthread.h>    // threads
#include <sys/time.h>   // gettimeofday
#include <unistd.h>     // write - usleep

#include "../rules/rules.h"

void	*coder(void *arg);

#endif
