/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/14 21:50:25 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	codex_destroy(t_sim *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_coders)
	{
		pthread_mutex_destroy(&((sim->dongles + 1)->mutex));
		pthread_cond_destroy(&((sim->dongles + 1)->cond));
	}
	pthread_mutex_destroy(&sim->log_mutex);
	free(sim->dongles);
	free(sim->coders);
	return ;
}
