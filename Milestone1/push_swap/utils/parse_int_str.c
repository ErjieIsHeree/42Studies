/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:04:19 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/12 03:09:45 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	accumulate_digits(const char *s, int j, int sign, long long *acc)
{
	while (s[j])
	{
		if (s[j] < '0' || s[j] > '9')
			return (0);
		*acc = *acc * 10 + (s[j] - '0');
		if (sign == 1 && *acc > 2147483647LL)
			return (0);
		if (sign == -1 && *acc > 2147483648LL)
			return (0);
		j++;
	}
	return (1);
}

int	parse_int_str(const char *s, int *is_valid)
{
	long long	acc;
	int			j;
	int			sign;

	if (!s || !is_valid)
		return (0);
	j = 0;
	sign = 1;
	acc = 0;
	if (s[j] == '+' || s[j] == '-')
	{
		if (s[j] == '-')
			sign = -1;
		j++;
	}
	if (!s[j])
		return ((*is_valid = 0), 0);
	if (!accumulate_digits(s, j, sign, &acc))
		return ((*is_valid = 0), 0);
	*is_valid = 1;
	return ((int)(acc * sign));
}
