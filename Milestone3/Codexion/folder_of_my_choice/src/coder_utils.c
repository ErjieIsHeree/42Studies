/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:11:09 by exia              #+#    #+#             */
/*   Updated: 2026/05/27 13:22:11 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	set_last_compile(t_coder *coder, long value)
{
	pthread_mutex_lock(&coder->coder_mutex);
	coder->last_compile = value;
	pthread_mutex_unlock(&coder->coder_mutex);
}

long	get_last_compile(t_coder *coder)
{
	long	val;

	pthread_mutex_lock(&coder->coder_mutex);
	val = coder->last_compile;
	pthread_mutex_unlock(&coder->coder_mutex);
	return (val);
}

void	add_compile_count(t_coder *coder)
{
	pthread_mutex_lock(&coder->coder_mutex);
	coder->compile_count++;
	pthread_mutex_unlock(&coder->coder_mutex);
}

long	get_compile_count(t_coder *coder)
{
	long	val;

	pthread_mutex_lock(&coder->coder_mutex);
	val = coder->compile_count;
	pthread_mutex_unlock(&coder->coder_mutex);
	return (val);
}

