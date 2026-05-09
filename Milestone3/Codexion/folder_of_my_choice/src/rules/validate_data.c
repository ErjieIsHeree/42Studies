/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:03:08 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 20:08:00 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

int	validate_data(t_rules *rules)
{
	if (rules->number_of_coders < 0 || rules->number_of_coders == INT_MAX)
		return (321);
	else if (rules->time_to_burnout < 0)
		return (322);
	else if (rules->time_to_compile < 0)
		return (323);
	else if (rules->time_to_debug < 0)
		return (324);
	else if (rules->time_to_refactor < 0)
		return (325);
	else if (rules->number_of_compiles_required < 0)
		return (326);
	else if (rules->dongle_cooldown < 0)
		return (327);
	else if (strcmp(rules->scheduler, "fifo") != 0 &&
	strcmp(rules->scheduler, "edf") != 0)
		return (328);
	return (0);
}
