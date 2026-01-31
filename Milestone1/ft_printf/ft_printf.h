/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:47:32 by exia              #+#    #+#             */
/*   Updated: 2026/01/27 18:47:11 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC "0123456789"
# define HEXA "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

//* Utils
int		ft_strlen(char	*str);

//* Chore
int		ft_printf(char const *a, ...);
void	putchr(char c, int *w_size);
void	putstr(char *str, int *w_size);
void	putnbr(int nbr, char *base, int *w_size);
void	putnbr_base(unsigned int nbr, char *base, int *w_size);
void	putptr_hexa(void *ptr, int *w_size);

#endif
