/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:32:11 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/27 14:47:41 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_invalid_n(char *n)
{
	int	i;

	if (strlen(n) > 10)
		return (1);
	i = 0;
	while (*(n + i))
		if (*n < '0' || *(n + i++) > '9')
			return (1);
	if (strcmp(n, "0") != 0 && atoi(n) == 0)
		return (1);
	return (0);
}

int	parse_data(int argc, char **argv, t_sim *sim)
{
	int	i;

	if (argc != 9)
		return (51);
	i = 0;
	while (++i < argc - 1)
		if (is_invalid_n(argv[i]))
			return (PARSING_ERRORS + i);
	sim->n_coders = atoi(argv[1]);
	sim->time_to_burnout = atoi(argv[2]);
	sim->time_to_compile = atoi(argv[3]);
	sim->time_to_debug = atoi(argv[4]);
	sim->time_to_refactor = atoi(argv[5]);
	sim->compiles_required = atoi(argv[6]);
	sim->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		sim->scheduler = FIFO;
	else if (strcmp(argv[8], "edf") == 0)
		sim->scheduler = EDF;
	else	
		return (PARSING_SCHEDULER_ERROR);
	return (0);
}
