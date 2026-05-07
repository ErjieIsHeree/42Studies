/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:18:17 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 12:08:27 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !! DELETE COMMENTS BEFORE EVAL

#ifndef RULES
#define RULES

#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct s_rules
{
    int     number_of_coders;
    int     time_to_burnout;
    int     time_to_compile;
    int     time_to_debug;
    int     time_to_refactor;
    int     number_of_compiles_required;
    int     dongle_cooldown;
    char    *scheduler;
}	t_rules;

int	get_rules(int argc, char **argv, t_rules *rules);
int	parse_data(int argc, char **argv, t_rules *rules);
int	validate_data(t_rules *rules);

#endif
