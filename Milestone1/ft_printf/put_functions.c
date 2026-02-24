/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:30:23 by exia              #+#    #+#             */
/*   Updated: 2026/02/02 09:54:38 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchr(char c, int *w_size)
{
	*w_size += write(1, &c, 1);
}

void	putstr(char *str, int *w_size)
{
	if (!str)
		putstr("(null)", w_size);
	else
		while (*str)
			putchr(*str++, w_size);
}

void	putnbr_base(unsigned long nbr, char *base, int *w_size)
{
	char	c;
	int		len;

	len = ft_strlen(base);
	if (nbr / len)
		putnbr_base(nbr / len, base, w_size);
	c = base[nbr % len];
	putchr(c, w_size);
}

void	putnbr(int nbr, char *base, int *w_size)
{
	unsigned int	n;

	if (nbr < 0)
	{
		putchr('-', w_size);
		n = (unsigned int)-nbr;
	}
	else
		n = (unsigned int)nbr;
	putnbr_base(n, base, w_size);
}

void	putptr_hexa(void *ptr, int *w_size)
{
	unsigned long	ulptr;

	if (!ptr)
	{
		putstr("(nil)", w_size);
		return ;
	}
	ulptr = (unsigned long)ptr;
	putstr("0x", w_size);
	putnbr_base(ulptr, HEXA, w_size);
}
