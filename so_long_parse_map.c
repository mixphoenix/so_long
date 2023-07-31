#include "so_long.h"

int ft_linesln(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

int ft_a_wall(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int ft_check_walls(char **lines)
{
	int x;
	int index;

	x = 0;
	index = 0;
	if(!lines)
		return (0);
	while (lines[index])
	{
		if ((index == 0) || (index == ft_linesln(lines)))
		{
			if(!ft_a_wall(lines[index]))
				return (0);
		}
		else
		{
			x = ft_strlen(lines[index]);
			if (lines[index][0] != '1' || lines[index][x - 1] != '1')
				return (0);	
		}
		index++;
	}
	return (1);
}

int check_size_line(char **lines)
{
	int i;

	i = 0;
	while (lines)
	{
		if (ft_strlen(lines[i]) != ft_strlen(lines[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

char **ft_store_map(char *file)
{
	int fd;
	char **lines;
	char *str;
	char *ptr;

	lines = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error();
	str = get_next_line(fd);
	ptr = NULL;
	while (str)
	{
		ptr = ft_strjoin(ptr, str);
		if (str && str[0] == '\n')
		{
			free(ptr);
			free(str);
			ft_error();
		}
		free(str);
		str = get_next_line(fd);
	}
	lines = ft_split(ptr, '\n');
	free (ptr);
	if(!lines)
		return (0);
	printf("fdsqfqsdfqsd\n");
	if (!check_size_line(lines))
		ft_error();
	if (!ft_check_walls(lines))
		ft_error();
	return (lines);
}

int ft_check_collectible(char **lines)
{
	int i;
	int j;
	int col;
	int exit;
	int P;

	i = 0;
	j = 0;
	exit = 0;
	col = 0;
	P = 0;
	while (lines[i])
	{
		while (lines[i][j])
		{
			if (lines[i][j] == 'C')
				col++;
			else if (lines[i][j] == 'E')
				exit++;
			else if (lines[i][j] == 'P')
				P++;	
			j++;
		}
		i++;
	}
	if ((col < 1) || (exit != 1) || (P != 1))
		return (0);
	return (1);
}
