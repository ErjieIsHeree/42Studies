/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:57:04 by exia              #+#    #+#             */
/*   Updated: 2026/01/25 20:28:20 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *param, ...)
{
	va_list	ap;
	int		i;
	size_t	len;

	if (!param)
		return (-1);
	va_start(ap, param);
	i = 0;
	len = ft_strlen(param);
	while (param[i] && len--)
	{
		if (param[i] == '%')
		{
			if (param[i +1])
				write_converted(ap, param[i +1]);
			i++;
			len--;
		}
		else
			write(1, &param[i], 1);
		i++;
	}
	va_end(ap);
}
