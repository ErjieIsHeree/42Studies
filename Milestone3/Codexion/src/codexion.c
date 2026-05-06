/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:52:52 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/06 23:16:46 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE ALL COMMENTS BEFORE EVALUATION
/**
 * ERRORS:
 * 	-100: Args erros
 * 		-101 Too few/many args (8 required, 9 if count program name)
 * 		-110 Parsing errors
 * 		-120 Validating errors
 * 
 * 	100: Sync variables initialization errors
 * 		101 Failed to initialize some thread
 * 		102 Failed to initialize some mutex
 * 		103 Failed to initialize some cond
 */

#include "codexion.h"

int	codex_init(t_rules *rules, t_table *table)
{
	int	i;

	memset(table->coders, 0, INT_MAX);
	memset(table->dongles, 0, INT_MAX);
	memset(table->coder_conds, 0, INT_MAX);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_create(&table->coders[i++], NULL, &f, (void *)rules) != 0)
			return (INT_MIN);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_mutex_init(&table->dongles[i++], NULL) != 0)
			return (i - 1);
	i = 0;
	while (i < rules->number_of_coders)
		if (pthread_cond_init(&table->coder_conds[i++], NULL) != 0)
			return ((-i) + 1);
	return (0);
}

int	error_codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	i;

	if (init_error < 0)
	{
		i = 0;
		while (i < init_error)
			pthread_mutex_destroy(&table->dongles[i++]);
		return (102);
	}
	else
	{
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(&table->dongles[i++]);
		i = 0;
		while (i < -init_error)
			pthread_cond_destroy(&table->coder_conds[i++]);
		return (103);
	}
}

int	codex_destroy(t_rules *rules, t_table *table, int init_error)
{
	int	error;
	int	i;

	error = 0;
	if (init_error == INT_MIN)
		return (101);
	if (init_error == 0)
	{
		i = 0;
		while (i < rules->number_of_coders)
			pthread_mutex_destroy(&table->dongles[i++]);
		i = 0;
		while (i < rules->number_of_coders)
			pthread_cond_destroy(&table->dongles[i++]);
	}
	else
		return (error_codex_destroy(rules, table, init_error));
	return (error);
}

int	codexion(int argc, char **argv)
{
	t_table	table;
	t_rules	rules;
	int		error;

	error = get_rules(argc, argv, &rules);
	if (error != 0)
		return error;
	error = codex_init(&rules, &table);
	if (error != 0)
		return (codex_destroy(&rules, &table, error));
	if (codex_start(&rules, &table) != 0)
	{
		codex_destroy(&rules, &table, 0);
		return (200);
	}
	error = codex_destroy(&rules, &table, 0);
	if (error != 0)
		return (error);
	return 0;
}
