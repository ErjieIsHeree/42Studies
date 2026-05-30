/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edf_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:06:50 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/30 18:40:01 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "../../codexion.h"

void	edf_push_coder(t_coder *coder, t_dongle *dongle)
{
	int	parent_node;
	int	coder_node;
	int	is_edf;

	is_edf = 0;
	coder_node = dongle->queue_size;
	dongle->queue[coder_node] = coder;
	while (!is_edf && coder_node != 0)
	{
		is_edf = 1;
		parent_node = coder_node / 2;
		if (get_last_compile(dongle->queue[parent_node])
			> get_last_compile(dongle->queue[coder_node]))
		{
			swap_queue_coders(&dongle->queue[parent_node],
				&dongle->queue[coder_node]);
			coder_node /= 2;
			is_edf = 0;
		}
	}
	dongle->queue_size++;
}

int	check_swap(t_dongle *dongle, int moving_node)
{
	int	left_node;
	int	right_node;

	left_node = 2 * moving_node + 1;
	right_node = 2 * moving_node + 2;
	if (right_node < dongle->queue_size
		&& get_last_compile(dongle->queue[left_node])
		> get_last_compile(dongle->queue[right_node])
		&& get_last_compile(dongle->queue[moving_node])
		> get_last_compile(dongle->queue[right_node]))
	{
		swap_queue_coders(&dongle->queue[left_node],
			&dongle->queue[moving_node]);
		return (right_node);
	}
	else if (left_node < dongle->queue_size
		&& get_last_compile(dongle->queue[left_node])
		< get_last_compile(dongle->queue[moving_node]))
	{
		swap_queue_coders(&dongle->queue[left_node],
			&dongle->queue[moving_node]);
		return (left_node);
	}
	return (0);
}

void	edf_pop_coder(t_dongle *dongle)
{
	int	moving_node;

	dongle->queue[0] = dongle->queue[dongle->queue_size - 1];
	dongle->queue_size--;
	moving_node = 0;
	while (1)
	{
		moving_node = check_swap(dongle, moving_node);
		if (!moving_node)
			break ;
		if (moving_node == dongle->queue_size - 1)
			break ;
	}
}
