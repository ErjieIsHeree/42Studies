/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:32:11 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/11 20:23:10 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

int	get_rules(int argc, char **argv, t_rules *rules)
{
	int	error;

	if (argc != 9)
		return (51);
	error = parse_data(argc, argv, rules);
	if (error != 0)
		return error;
	error = validate_data(rules);
	if (error != 0)
		return error;
	return 0;
}

