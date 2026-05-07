/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 18:22:06 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	error_codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	i;

	if (init_error < 0)
	{
		i = 0;
		while (i < init_error)
			pthread_mutex_destroy(table->dongles + i++);
		return (102);
	}
	else
	{
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(&table->dongles + i++);
		i = 0;
		while (i < -init_error)
			pthread_cond_destroy(&table->coder_conds + i++);
		return (103);
	}
}

int	codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	i;

	if (init_error == INT_MIN)
		return (101);
	if (init_error == 0)
	{
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(&table->dongles[i++]);
		i = 0;
		while (i < rules->number_of_coders)
			pthread_cond_destroy(&table->coder_conds[i++]);
		return (0);
	}
	else
		return (error_codex_destroy(rules, table, init_error));
}
