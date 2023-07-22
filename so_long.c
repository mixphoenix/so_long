#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber"))
			ft_error();
		printf("OK");
	}
	return (0);
}