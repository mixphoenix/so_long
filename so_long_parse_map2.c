#include "so_long.h"

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
