#include "so_long.h"

char **ft_check_map(char **av)
{
    t_data_map map_coll;
    char **lines;

	if (!ft_strcmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber"))
		ft_error();
	lines = ft_store_map(av[1]);
	if (!lines)
		ft_error();
    return(lines);
}