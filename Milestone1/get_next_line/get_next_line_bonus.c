/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:01:30 by exia              #+#    #+#             */
/*   Updated: 2026/02/05 12:38:18 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	nl_at(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (*str)
	{
		if (*str == '\n')
			return (i);
		i++;
		str++;
	}
	return (-1);
}

char	*str_next(char *str)
{
	char	*new_str;
	size_t	new_s_size;
	size_t	remain_size;

	if (!str)
		return (NULL);
	if (nl_at(str) == -1)
	{
		new_str = ft_strdup(str);
		str[0] = 0;
		return (new_str);
	}
	new_s_size = nl_at(str) + 1;
	remain_size = ft_strlen(str) - new_s_size;
	new_str = ft_calloc(new_s_size + 1, 1);
	ft_memmove(new_str, str, new_s_size);
	ft_memmove(str, &str[new_s_size], remain_size);
	str[remain_size] = 0;
	return (new_str);
}

int	init(char **memory, char **buff, int fd)
{
	size_t	buff_s;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff_s = (size_t)BUFFER_SIZE;
	if (!*memory)
		*memory = (char *)ft_calloc(buff_s, 1);
	if (!*memory)
		return (0);
	*buff = (char *)ft_calloc(buff_s +1, 1);
	if (!*buff)
		return (free(*memory), 0);
	(*buff)[1] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*memory[1025];
	char		*buff;
	int			read_state;
	char		*t;

	if (!init(&memory[fd], &buff, fd))
		return (NULL);
	while (nl_at(memory[fd]) == -1)
	{
		read_state = read(fd, buff, BUFFER_SIZE);
		if (read_state == -1 || (!*memory[fd] && !*buff && read_state == 0))
			return (free(memory[fd]), free(buff), NULL);
		t = memory[fd];
		memory[fd] = strjoin(memory[fd], buff, read_state);
		free(t);
		if (read_state == 0)
			return (free(buff), str_next(memory[fd]));
	}
	free(buff);
	return (str_next(memory[fd]));
}
