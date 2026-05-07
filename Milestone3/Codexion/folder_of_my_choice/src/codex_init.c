/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:16:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 10:45:08 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	codex_init(t_rules *rules, t_table *table)
{
	int	i;

	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_create(&table->coders[i++], NULL, coder, NULL) != 0)
			return (INT_MIN);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_mutex_init(&table->dongles[i++], NULL) != 0)
			return (--i);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_cond_init(&table->coder_conds[i++], NULL) != 0)
			return (-(--i));
	return (0);
}
