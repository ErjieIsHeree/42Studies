/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:16:10 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 19:40:32 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	codex_init(t_rules *rules, t_table *table)
{
	int	i;

	table->coder = malloc(sizeof(pthread_t) * rules->number_of_coders);
	table->dongle = malloc(sizeof(pthread_mutex_t) * rules->number_of_coders);
	table->dongle_cond = malloc(
		sizeof(pthread_cond_t) * rules->number_of_coders);
	if (!table->coder | !table->dongle | !table->dongle_cond)
		return (INT_MIN);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_create(table->coder + i++, NULL, coder, NULL) != 0)
			return (INT_MIN);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_mutex_init(table->dongle + i++, NULL) != 0)
			return (--i);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_cond_init(table->dongle_cond + i++, NULL) != 0)
			return (-(--i));
	return (0);
}
