/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:09 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/05 15:44:47 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *str, int *i_sum)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", i_sum);
		return ;
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		sum(i_sum, 1);
		i++;
	}
}
