/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:11:21 by exia              #+#    #+#             */
/*   Updated: 2026/05/27 13:23:19 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_coder	*get_first_coder(pthread_mutex_t *queue_mutex, t_coder **queue)
{
	t_coder	*c;
	
	pthread_mutex_lock(queue_mutex);
	c = queue[0];
	pthread_mutex_unlock(queue_mutex);
	return (c);
}
