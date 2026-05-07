/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:03:08 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 09:52:34 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

int	validate_data(t_rules *rules)
{
	if (rules->number_of_coders < 0 || rules->number_of_coders == INT_MAX)
		return (-121);
	else if (rules->time_to_burnout < 0)
		return (-122);
	else if (rules->time_to_compile < 0)
		return (-123);
	else if (rules->time_to_debug < 0)
		return (-124);
	else if (rules->time_to_refactor < 0)
		return (-125);
	else if (rules->number_of_compiles_required < 0)
		return (-126);
	else if (rules->dongle_cooldown < 0)
		return (-127);
	else if (strcmp(rules->scheduler, "fifo") != 0 ||
	strcmp(rules->scheduler, "edf") != 0)
		return (-128);
	return (0);
}
