#include "so_long.h"

char **ft_store_map_util(char **ptr)
{
	char	**lines;

	lines = ft_split(*ptr, '\n');
	if (!lines)
		ft_error();
	if (!check_size_line(lines))
		ft_error();
	free(*ptr);
	if (!ft_check_walls(lines))
		ft_error();
	return (lines);
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
	lines = ft_store_map_util(&ptr);
	return (lines);
}

// void	ft_check_collectible_util(char **lines,t_data_map map_collect, int i, int j)
// {
// 	while (lines[i][++j])
// 	{
// 		if (lines[i][j] == 'C')
// 			map_collect.collectibles++;
// 		else if (lines[i][j] == 'P')
// 			map_collect.player_pos++;
// 		else if (lines[i][j] == 'E')
// 			map_collect.exit++;
// 	}
// }

void initialization_norm(t_data_map *map_collect)
{
	map_collect->collectibles = 0;
	map_collect->player_pos = 0;
	map_collect->exit = 0;
}

t_data_map	ft_check_collectible(char **lines, int mark)
{
	t_data_map	map_collect;
	int			i;
	int			j;

	i = -1;
	initialization_norm(&map_collect);
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j++])
		{
			if (lines[i][j] == 'C')
				map_collect.collectibles++;
			else if (lines[i][j] == 'P')
				map_collect.player_pos++;
			else if (lines[i][j] == 'E')
				map_collect.exit++;
		}
	}
	if (mark == 1 && (map_collect.collectibles < 1 || map_collect.exit != 1
		|| map_collect.player_pos != 1))
		ft_error();
	return (map_collect);
}
