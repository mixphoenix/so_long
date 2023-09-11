#include "so_long.h"

void	ft_moveup(t_game *mlx, int *collectibles)
{
	if (mlx->map[mlx->pos.i - 1][mlx->pos.j] == '1')
		return ;
	if (mlx->map[mlx->pos.i - 1][mlx->pos.j] == '0')
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j], &mlx->map[mlx->pos.i
			- 1][mlx->pos.j]);
	if (mlx->map[mlx->pos.i - 1][mlx->pos.j] == 'C')
	{
		mlx->map[mlx->pos.i - 1][mlx->pos.j] = '0';
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j], &mlx->map[mlx->pos.i
			- 1][mlx->pos.j]);
		collectibles--;
	}
	if (mlx->map[mlx->pos.i - 1][mlx->pos.j] == 'E')
	{
		if (*collectibles != 0)
			return ;
		else
		{
			ft_printf("GOOD JOB!\n");
			exit(0);
		}
	}
	ft_printf("moves : %d\n", ++(mlx->counter));
}

void	ft_movedown(t_game *mlx, int *collectibles)
{
	if (mlx->map[mlx->pos.i + 1][mlx->pos.j] == '1')
		return ;
	if (mlx->map[mlx->pos.i + 1][mlx->pos.j] == '0')
		ft_swap(&(mlx->map)[mlx->pos.i][mlx->pos.j], &(mlx->map)[mlx->pos.i
			+ 1][mlx->pos.j]);
	if (mlx->map[mlx->pos.i + 1][mlx->pos.j] == 'C')
	{
		mlx->map[mlx->pos.i + 1][mlx->pos.j] = '0';
		ft_swap(&(mlx->map)[mlx->pos.i][mlx->pos.j], &(mlx->map)[mlx->pos.i
			+ 1][mlx->pos.j]);
		collectibles--;
	}
	if (mlx->map[mlx->pos.i + 1][mlx->pos.j] == 'E')
	{
		if (*collectibles != 0)
			return ;
		else
		{
			ft_printf("GOOD JOB!\n");
			exit(0);
		}
	}
	ft_printf("moves : %d\n", ++(mlx->counter));
}

void	ft_moveright(t_game *mlx, int *collectibles)
{
	if (mlx->map[mlx->pos.i][mlx->pos.j + 1] == '1')
		return ;
	if (mlx->map[mlx->pos.i][mlx->pos.j + 1] == '0')
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j],
			&mlx->map[mlx->pos.i][mlx->pos.j + 1]);
	if (mlx->map[mlx->pos.i][mlx->pos.j + 1] == 'C')
	{
		mlx->map[mlx->pos.i][mlx->pos.j + 1] = '0';
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j],
			&mlx->map[mlx->pos.i][mlx->pos.j + 1]);
		collectibles--;
	}
	if (mlx->map[mlx->pos.i][mlx->pos.j + 1] == 'E')
	{
		if (*collectibles != 0)
			return ;
		else
		{
			ft_printf("GOOD JOB!\n");
			exit(0);
		}
	}
	ft_printf("moves : %d\n", ++(mlx->counter));
}

void	ft_moveleft(t_game *mlx, int *collectibles)
{
	if (mlx->map[mlx->pos.i][mlx->pos.j - 1] == '1')
		return ;
	if (mlx->map[mlx->pos.i][mlx->pos.j - 1] == '0')
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j],
			&mlx->map[mlx->pos.i][mlx->pos.j - 1]);
	if (mlx->map[mlx->pos.i][mlx->pos.j - 1] == 'C')
	{
		mlx->map[mlx->pos.i][mlx->pos.j - 1] = '0';
		ft_swap(&mlx->map[mlx->pos.i][mlx->pos.j],
			&mlx->map[mlx->pos.i][mlx->pos.j - 1]);
		collectibles--;
	}
	if (mlx->map[mlx->pos.i][mlx->pos.j - 1] == 'E')
	{
		if (*collectibles != 0)
			return ;
		else
		{
			ft_printf("GOOD JOB!\n");
			exit(0);
		}
	}
	ft_printf("moves : %d\n", ++(mlx->counter));
}

int	ft_close(t_game *mlx)
{
	mlx_destroy_window(mlx->mlx_init, mlx->mlx_window);
	exit(0);
	return (0);
}
