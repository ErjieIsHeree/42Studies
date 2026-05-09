/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:02:55 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 20:07:05 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

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

int	parse_data(int argc, char **argv, t_rules *rules)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
		if (is_invalid_n(argv[i]))
			return (310 + i);
	rules->number_of_coders = atoi(argv[1]);
	rules->time_to_burnout = atoi(argv[2]);
	rules->time_to_compile = atoi(argv[3]);
	rules->time_to_debug = atoi(argv[4]);
	rules->time_to_refactor = atoi(argv[5]);
	rules->number_of_compiles_required = atoi(argv[6]);
	rules->dongle_cooldown = atoi(argv[7]);
	rules->scheduler = argv[8];
	return (0);
}
