#include "so_long.h"

int main(int ac, char **av)
{
	//int i;
	//char *line_ber;

	//i = 0;
	if (ac == 2)
	{
		if (ft_strcmp(ft_strnstr(av[1], ".ber", ft_strlen(av[1])), ".ber"))
			ft_error();
		else
			printf("OK");
	}
	return (0);
}