/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:06:56 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 11:37:44 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include "../../codexion_types.h"

void	fifo_push_coder(t_coder *coder, t_dongle *queue);
void	edf_push_coder(t_coder *coder, t_dongle *queue);

void	pop_coder(t_coder *coder, t_dongle *dongle);

#endif
