/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:06:56 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/22 22:30:39 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP
#define HEAP

#include "../../codexion_types.h"

void	fifo_push_coder(t_coder *coder, t_dongle *queue);
void	edf_push_coder(t_coder *coder, t_dongle *queue);

void	pop_coder(t_coder *coder, t_dongle *dongle);

#endif
