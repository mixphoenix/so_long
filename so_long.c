#include "so_long.h"

int main(int ac, char **av)
{
	t_data_map map_coll;
	char **lines;
	int i;

	i = 0;
	if (ac == 2)
	{
		lines = ft_check_map(av[1]);
		map_coll = ft_check_collectible(lines);
	}
	else
		ft_error();
	return (0);
}