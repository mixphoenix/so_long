#include "so_long.h"

char	**map_dup(char **lines)
{
	int		i;
	int		len;
	char	**map;

	i = -1;
	len = ft_linesln(lines) + 1;
	map = (char **)malloc(sizeof(char *) * len);
	if (!map)
		return (NULL);
	while (lines[++i])
		map[i] = ft_strdup(lines[i]);
	map[i] = NULL;
	return (map);
}

int	ft_dfs_checker(char c)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '0')
		return (1);
	return (0);
}

void	ft_debth_f_s(char **map, int i, int j)
{
	t_data_map	map_collect;

	map_collect = ft_rcol(map);
	if (map[i][j] == 'E')
		map[i][j] = '1';
	if (i < 1 || i > map_collect.r || j < 0 || j > map_collect.col
		|| ft_dfs_checker(map[i][j]))
		return ;
	else
	{
		map[i][j] = 'N';
		ft_debth_f_s(map, i + 1, j);
		ft_debth_f_s(map, i, j + 1);
		ft_debth_f_s(map, i - 1, j);
		ft_debth_f_s(map, i, j - 1);
	}
}

void	ft_flood_fill(char **lines)
{
	t_player_pos	pos;
	t_data_map		map_collect;
	char			**map;

	map = map_dup(lines);
	pos = ft_get_player_pos(lines);
	ft_debth_f_s(map, pos.i, pos.j);
	map_collect = ft_check_collectible(map, 0);
	ft_free_double_ptr(map);
	if (map_collect.collectibles != 0 || map_collect.exit != 0
		|| map_collect.player_pos != 0)
		ft_error();
}
