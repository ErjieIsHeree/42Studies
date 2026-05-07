/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erjieisheree <erjieisheree@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:36 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/07 11:53:55 by erjieishere      ###   ########.fr       */
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

void	*coder(void *arg)
{
	return arg;
}

int	codex_start(t_rules *rules, t_table *table)
{
	printf("wow%p%p", rules, table);
	return (0);
}

