/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:40:07 by exia              #+#    #+#             */
/*   Updated: 2026/05/30 18:32:01 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "../../codexion.h"

void	fifo_push_coder(t_coder *coder, t_dongle *dongle)
{
	dongle->queue[dongle->queue_size] = coder;
	dongle->queue_size++;
}

int	shift_down(t_dongle *dongle, int moving_node)
{
	int	left;
	int	right;

	right = 2 * moving_node + 2;
	while (right < dongle->queue_size)
	{
		swap_queue_coders(&dongle->queue[moving_node], &dongle->queue[right]);
		moving_node = right;
		right = 2 * moving_node + 2;
	}
	left = 2 * moving_node + 1;
	if (left < dongle->queue_size)
		swap_queue_coders(&dongle->queue[moving_node], &dongle->queue[left]);
	return (0);
}

void	fifo_pop_coder(t_dongle *dongle)
{
	dongle->queue[0] = dongle->queue[dongle->queue_size - 1];
	dongle->queue_size--;
	shift_down(dongle, 0);
}
