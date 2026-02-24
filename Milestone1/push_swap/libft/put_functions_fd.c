/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:02:47 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 04:58:34 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putchr_fd(int fd, char c, int *w_size)
{
	*w_size += write(fd, &c, 1);
}

void	putstr_fd(int fd, char *str, int *w_size)
{
	if (!str)
		putstr_fd(fd, "(null)", w_size);
	else
		while (*str)
			putchr_fd(fd, *str++, w_size);
}

void	putnbr_base_fd(int fd, unsigned long nbr, char *base, int *w_size)
{
	char	c;
	int		len;

	len = printf_strlen(base);
	if (nbr / len)
		putnbr_base_fd(fd, nbr / len, base, w_size);
	c = base[nbr % len];
	putchr_fd(fd, c, w_size);
}

void	putnbr_fd(int fd, int nbr, char *base, int *w_size)
{
	unsigned int	n;

	if (nbr < 0)
	{
		putchr_fd(fd, '-', w_size);
		n = (unsigned int)-nbr;
	}
	else
		n = (unsigned int)nbr;
	putnbr_base_fd(fd, n, base, w_size);
}

void	putptr_hexa_fd(int fd, void *ptr, int *w_size)
{
	unsigned long	ulptr;

	if (!ptr)
	{
		putstr_fd(fd, "(nil)", w_size);
		return ;
	}
	ulptr = (unsigned long)ptr;
	putstr_fd(fd, "0x", w_size);
	putnbr_base_fd(fd, ulptr, HEXA, w_size);
}
