#include "so_long.h"

int	main(int ac, char **av)
{
	char **lines;

	if (ac == 2)
	{
		lines = ft_check_map(av);
		ft_check_collectible(lines, 1);
		ft_flood_fill(lines);
		ft_game(lines);
	}
	else
		ft_error();
	return (0);
}