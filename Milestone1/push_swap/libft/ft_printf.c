/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:57:04 by exia              #+#    #+#             */
/*   Updated: 2026/02/12 04:48:51 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_conversion_fd(int fd, va_list ap, const char rule,
				int *w_size)
{
	if (rule == 'c')
		putchr_fd(fd, va_arg(ap, int), w_size);
	else if (rule == 's')
		putstr_fd(fd, va_arg(ap, char *), w_size);
	else if (rule == 'p')
		putptr_hexa_fd(fd, va_arg(ap, void *), w_size);
	else if (rule == 'd' || rule == 'i')
		putnbr_fd(fd, va_arg(ap, int), DEC, w_size);
	else if (rule == 'u')
		putnbr_base_fd(fd, va_arg(ap, unsigned int), DEC, w_size);
	else if (rule == 'x')
		putnbr_base_fd(fd, va_arg(ap, unsigned int), HEXA, w_size);
	else if (rule == 'X')
		putnbr_base_fd(fd, va_arg(ap, unsigned int), HEXA_UPPER, w_size);
	else if (rule == '%')
		putchr_fd(fd, '%', w_size);
	else
	{
		putchr_fd(fd, '%', w_size);
		putchr_fd(fd, rule, w_size);
	}
}

static void	write_conversion(va_list ap, const char rule,
				int *w_size)
{
	if (rule == 'c')
		putchr(va_arg(ap, int), w_size);
	else if (rule == 's')
		putstr(va_arg(ap, char *), w_size);
	else if (rule == 'p')
		putptr_hexa(va_arg(ap, void *), w_size);
	else if (rule == 'd' || rule == 'i')
		putnbr(va_arg(ap, int), DEC, w_size);
	else if (rule == 'u')
		putnbr_base(va_arg(ap, unsigned int), DEC, w_size);
	else if (rule == 'x')
		putnbr_base(va_arg(ap, unsigned int), HEXA, w_size);
	else if (rule == 'X')
		putnbr_base(va_arg(ap, unsigned int), HEXA_UPPER, w_size);
	else if (rule == '%')
		putchr('%', w_size);
	else
	{
		putchr('%', w_size);
		putchr(rule, w_size);
	}
}

int	ft_printf(char const *str, ...)
{
	int		w_size;
	va_list	ap;

	if (!str)
		return (-1);
	w_size = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				write_conversion(ap, *str, &w_size);
			else
				return (-1);
		}
		else
			w_size += write(1, &(*str), 1);
		str++;
	}
	va_end(ap);
	return (w_size);
}

int	ft_dprintf(int fd, char const *str, ...)
{
	int		w_size;
	va_list	ap;

	if (!str)
		return (-1);
	w_size = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				write_conversion_fd(fd, ap, *str, &w_size);
			else
				return (-1);
		}
		else
			w_size += write(fd, &(*str), 1);
		str++;
	}
	va_end(ap);
	return (w_size);
}
