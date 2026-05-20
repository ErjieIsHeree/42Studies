/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:06:50 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/20 20:23:35 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	fifo_push_coder(t_coder *coder, t_dongle *dongle)
{
	if (dongle->queue_size == 0)
		dongle->queue[0] = coder;
	else
		dongle->queue[1] = coder;
	dongle->queue_size++;
	return ;
}

void	edf_push_coder(t_coder *coder, t_dongle *dongle)
{
	t_coder	*temp_coder;

	if (dongle->queue_size == 0)
		dongle->queue[0] = coder;
	else
	{
		if (coder->last_compile >= dongle->queue[0]->last_compile)
			dongle->queue[1] = coder;
		else
		{
			temp_coder = dongle->queue[0];
			dongle->queue[0] = coder;
			dongle->queue[1] = temp_coder;
		}
	}
	dongle->queue_size++;
	return ;
}
void	pop_coder(t_dongle *dongle)
{
	if (dongle->queue_size == 2)
		dongle->queue[0] = dongle->queue[1];
	dongle->queue[1] = NULL;
	dongle->queue_size--;
	return ;
}
