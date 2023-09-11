#include "so_long.h"

int	ft_linesln(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

int	ft_a_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_walls(char **lines)
{
	int	x;
	int	index;

	x = 0;
	index = 0;
	if (!lines)
		return (0);
	while (lines[index])
	{
		if ((index == 0) || index == (ft_linesln(lines) - 1))
		{
			if (!ft_a_wall(lines[index]))
				return (0);
		}
		x = ft_strlen(lines[index]);
		if (lines[index][0] != '1' || lines[index][x - 1] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	check_size_line(char **lines)
{
	int	i;

	i = 0;
	while ((lines[i] != NULL) && (lines[i + 1] != NULL))
	{
		if (ft_strlen(lines[i]) != ft_strlen(lines[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

char	**ft_store_map(char *file)
{
	int		fd;
	char	**lines;
	char	*str;
	char	*ptr;

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
	if(!lines)
		ft_error();
	if (!check_size_line(lines))
		ft_error();
	free(ptr);
	if (!lines)
		return (0);
	if (!ft_check_walls(lines))
		ft_error();
	return (lines);
}

t_data_map	ft_check_collectible(char **lines, int mark)
{
	t_data_map	map_collect;
	int			i;
	int			j;

	i = 0;
	map_collect.collectibles = 0;
	map_collect.player_pos = 0;
	map_collect.exit = 0;
	while (lines[i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'C')
				map_collect.collectibles++;
			else if (lines[i][j] == 'P')
				map_collect.player_pos++;
			else if (lines[i][j] == 'E')
				map_collect.exit++;
		}
		i++;
	}
	if (mark == 1)
	{
		if (map_collect.collectibles < 1 || map_collect.exit != 1
			|| map_collect.player_pos != 1)
			ft_error();
	}
	return (map_collect);
}
