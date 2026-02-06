/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:46 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/05 15:44:50 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putunsnbr(unsigned int nb, int *i_sum)
{
	char	temp;

	if (nb >= 10)
		ft_putnbr(nb / 10, i_sum);
	temp = (nb % 10) + '0';
	write(1, &temp, 1);
	sum(i_sum, 1);
}
