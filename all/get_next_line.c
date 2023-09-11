/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmisk <abmisk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:43:11 by abmisk            #+#    #+#             */
/*   Updated: 2023/07/22 02:43:11 by abmisk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static char	*get_reserve(int fd, char *buffer, char **reserve)
{
	char	*p;
	ssize_t	readline;

	p = 0;
	readline = 1;
	while (readline != 0)
	{
		readline = read(fd, buffer, BUFFER_SIZE);
		if (readline == -1)
		{
			free(*reserve);
			*reserve = NULL;
			return (NULL);
		}
		else if (readline == 0)
			break ;
		buffer[readline] = '\0';
		p = *reserve;
		*reserve = gnl_strjoin(p, buffer);
		free(p);
		p = NULL;
		if (*reserve && gnl_strchr(*reserve, '\n'))
			break ;
	}
	return (*reserve);
}

static char	*subresrve(char *get_line)
{
	char	*reserve;
	size_t	i;

	i = 0;
	while (get_line[i] != '\n' && get_line[i] != '\0')
		i++;
	if (get_line[i] == '\0' || get_line[i + 1] == '\0')
		return (0);
	reserve = gnl_substr(get_line, i + 1, gnl_strlen(get_line) - i);
	if (!reserve)
	{
		free(reserve);
		reserve = NULL;
	}
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	char		*cat;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get_reserve(fd, buffer, &reserve);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	reserve = subresrve(line);
	cat = line;
	line = gnl_substr(cat, 0, find(line) + 1);
	free(cat);
	cat = NULL;
	return (line);
}
