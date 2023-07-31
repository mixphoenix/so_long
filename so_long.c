#include "so_long.h"

int main(int ac, char **av)
{
	char **lines;


	if (ac == 2)
	{
		if (!ft_strcmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber"))
			ft_error();
		lines = ft_store_map(av[1]);
		//printf("qsdfsqdfqsd\n");
	}
	else
		ft_error();
	return (0);
}