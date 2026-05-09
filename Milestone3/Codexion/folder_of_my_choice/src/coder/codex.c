/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/09 20:32:15 by erjieishere      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *  100: Sync variables initialization errors
 * 		101 Failed to initialize some thread
 * 		102 Failed to initialize some mutex
 * 		103 Failed to initialize some cond
 */

#include "codex.h"
#include <stdio.h>

/**
 * Thread have in mind items:
 * time_to_burnout
 * time_to_compile
 * time_to_debug
 * time_to_refactor
 * number_of_compiles_required
 * scheduler
 */

void	*coder(void *arg)
{
	return (arg);
}
