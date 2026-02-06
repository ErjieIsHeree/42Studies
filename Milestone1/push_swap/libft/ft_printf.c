/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:04:31 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/05 15:44:40 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puthex(uintptr_t ptr, int u, int *i_sum)
{
	char	*hex_l;
	char	*hex_u;

	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	if (ptr >= 16)
		ft_puthex(ptr / 16, u, i_sum);
	if (u)
		ft_putchar(hex_u[ptr % 16], i_sum);
	else
		ft_putchar(hex_l[ptr % 16], i_sum);
}

void	ft_putptr(void *ptr, int *i_sum)
{
	if (!ptr)
		return (ft_putstr("(nil)", i_sum), (void)0);
	ft_putstr("0x", i_sum);
	ft_puthex((uintptr_t)ptr, 0, i_sum);
}

void	select_char(char const *str, va_list args, int *i_sum)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), i_sum);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), i_sum);
	else if (*str == 'p')
		ft_putptr(va_arg(args, void *), i_sum);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), i_sum);
	else if (*str == 'u')
		ft_putunsnbr(va_arg(args, unsigned int), i_sum);
	else if (*str == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, i_sum);
	else if (*str == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, i_sum);
	else if (*str == '%')
		ft_putchar('%', i_sum);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i_sum;

	i_sum = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			select_char(str, args, &i_sum);
		}
		else
		{
			ft_putchar(*str, &i_sum);
		}
		if (*str)
			str++;
	}
	va_end(args);
	return (i_sum);
}
