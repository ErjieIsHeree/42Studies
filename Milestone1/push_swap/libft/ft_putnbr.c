/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:26 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/05 17:39:06 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int nb, int *i_sum)
{
	char	temp;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		sum(i_sum, 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		sum(i_sum, 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, i_sum);
	temp = (nb % 10) + '0';
	write(1, &temp, 1);
	sum(i_sum, 1);
}
