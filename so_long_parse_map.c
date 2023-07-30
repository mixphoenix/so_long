#include "so_long.h"

int ft_linesln(char **lines)
{
	int i;

	i = 0;
	while (lines[i] != '\0')
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

void ft_check_walls(char **lines, int index)
{
	int x;

	x = 0;
	while (lines[index])
	{
		if ((index == 0) || (index == ft_linesln(lines)))
		{
			if(!ft_a_wall(lines[index]))
				ft_error();
		}
		else
		{
			x = ft_strlen(lines[index]);
			if (lines[index][0] != '1' || lines[index][x - 1] != '1')
				ft_error();	
		}
		index++;
	}
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

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error();
	str = get_next_line(fd);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
		{
			free(str);
			str = NULL;
			ft_error();
		}
	}
	lines = ft_split(str, '\n');
	if (!check_size_line(lines))
		ft_error();
	return (lines);
}