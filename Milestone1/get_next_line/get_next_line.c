/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:01:30 by exia              #+#    #+#             */
/*   Updated: 2026/01/31 20:59:23 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	strjoin_nl(char *s1, char *s2)
{
	return (0);
}

static int	has_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

static char	*buf_next(char *buf)
{
	char	*new_str;
	char	*buf2;
	size_t	s_size;
	int		i;

	if (!buf)
		return (NULL);
	s_size = ft_strlen_c(buf, '\n');
	new_str = ft_calloc(s_size + 1, 1);
	if (!new_str)
		return (NULL);
	i = 0;
	if (has_nl(buf))
	{
		while (i < s_size)
			new_str[i] = buf[i++];
		while (buf[i])
			*buf++ = buf[i];
	}
	else
		while (i < s_size)
			new_str[i] = buf[i++];
	*buf = 0;
	new_str[i] = 0;
	return (new_str);
}

//TODO: need to control fd? how?
//TODO: need to control BUFFER_SIZE???? HOw?
//TODO: char *strjoin_nl(char *s1, char *s2) function: cant return NULL, both params can be, also gotta free MEM pointer. Function return a string until a \n or a \0 in normal cases
//? read: just override the necesary positions
char	*get_next_line(int fd)
{
	char		*mem;
	static char	*buf;
	int			read_state;

	if (has_nl(buf))
		return (buf_next(buf));
	if (!buf)
		buf = ft_calloc(BUFFER_SIZE, 1);
	mem = ft_strdup(buf);
	read_state = 1;
	while (!has_nl(mem) && read_state != 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		read_state = read(fd, buf, BUFFER_SIZE);
		if (read_state == -1)
			return (free(mem), free(buf), NULL);
		mem = strjoin_nl(mem, buf_next(buf)); // READ UR NOTEBOOK, FOR REAL
		if (!mem)
			return (free(buf), NULL);
	}
	return (mem);
}
