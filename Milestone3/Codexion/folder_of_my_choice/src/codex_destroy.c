/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:15:21 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 20:22:14 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	free_all(t_table *table)
{
	int	error;

	error = 0;
	if (!table->coder | !table->dongle | !table->dongle_cond)
		error = 1;
	if (table->coder)
		free(table->coder);
	if (table->dongle)
		free(table->dongle);
	if (table->dongle_cond)
		free(table->dongle_cond);
	return (error);
}

int	error_codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	i;
	
	if (init_error < 0)
	{
		i = 0;
		while (i < init_error)
			pthread_mutex_destroy(table->dongle + i++);
		return (102);
	}
	else if (init_error > 0)
	{
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(table->dongle + i++);
		i = 0;
		while (i < -init_error)
			pthread_cond_destroy(table->dongle_cond + i++);
		return (103);
	}
	if (free_all(table) != 0)
		return (104);
	return (101);
}

int	codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	i;

	if (init_error == 0)
	{
		printf("\n%d\n", rules->number_of_coders);
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(table->dongle + i++);
		i = 0;
		while (i < rules->number_of_coders)
			pthread_cond_destroy(table->dongle_cond + i++);
		free_all(table);
		return (0);
	}
	else
		return (error_codex_destroy(rules, table, init_error));
}
