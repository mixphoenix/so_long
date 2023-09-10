#include "so_long.h"

t_data_map ft_rcol(char **lines)
{
	t_data_map map_collect;

	map_collect.r = ft_linesln(lines) - 1;
	map_collect.col = ft_strlen(lines[0]) - 1;
	return (map_collect);
}

char **ft_check_map(char **av)
{
    // t_data_map map_coll;
    char **lines;
	int i;
	int j;

	i = -1;
	if (!ft_strcmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber"))
		ft_error();
	lines = ft_store_map(av[1]);
	if (!lines)
		ft_error();
	while(lines[++i])
	{
		j = 0;
		while(lines[i][j])
		{
			if (lines[i][j] != 'C' && lines[i][j] != 'P' \
				&& lines[i][j] != 'E' && lines[i][j] != '0' \
				&& lines[i][j] != '1')
				ft_error();
			j++;
		}
	}
    return(lines);
}