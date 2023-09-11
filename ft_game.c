#include "so_long.h"

void	ft_import_images(t_game *mlx)
{
	mlx->mlx_coin = mlx_xpm_file_to_image(mlx->mlx_init,
			"./textures/mlx_coin.xpm", &mlx->w, &mlx->h);
	mlx->mlx_player = mlx_xpm_file_to_image(mlx->mlx_init,
			"./textures/mlx_player.xpm", &mlx->w, &mlx->h);
	mlx->mlx_exit = mlx_xpm_file_to_image(mlx->mlx_init,
			"./textures/mlx_exit.xpm", &mlx->w, &mlx->h);
	mlx->mlx_wall = mlx_xpm_file_to_image(mlx->mlx_init,
			"./textures/mlx_wall.xpm", &mlx->w, &mlx->h);
	mlx->mlx_ground = mlx_xpm_file_to_image(mlx->mlx_init,
			"./textures/mlx_ground.xpm", &mlx->w, &mlx->h);
	if (!mlx->mlx_coin || !mlx->mlx_player || !mlx->mlx_exit || !mlx->mlx_wall
		|| !mlx->mlx_ground)
		ft_error();
}

void	ft_utils_put_images(t_game mlx, int i, int j)
{
	if (mlx.map[i][j] == 'C')
		mlx_put_image_to_window(mlx.mlx_init, mlx.mlx_window,
			mlx.mlx_coin, j * 80, i * 80);
	else if (mlx.map[i][j] == 'P')
		mlx_put_image_to_window(mlx.mlx_init, mlx.mlx_window,
			mlx.mlx_player, j * 80, i * 80);
	else if (mlx.map[i][j] == 'E')
		mlx_put_image_to_window(mlx.mlx_init, mlx.mlx_window,
			mlx.mlx_exit, j * 80, i * 80);
	else if (mlx.map[i][j] == '1')
		mlx_put_image_to_window(mlx.mlx_init, mlx.mlx_window,
			mlx.mlx_wall, j * 80, i * 80);
	else if (mlx.map[i][j] == '0')
		mlx_put_image_to_window(mlx.mlx_init, mlx.mlx_window,
			mlx.mlx_ground, j * 80, i * 80);
}

void	ft_put_images(t_game mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx.map[++i])
	{
		j = 0;
		while (mlx.map[i][j])
			ft_utils_put_images(mlx, i, j++);
	}
}

int	ft_move(int keycode, t_game *mlx)
{
	t_data_map	info;

	info = ft_check_collectible(mlx->map, 0);
	mlx->pos = ft_get_player_pos(mlx->map);
	if (keycode == 126)
		ft_moveup(mlx, &(info.collectibles));
	if (keycode == 125)
		ft_movedown(mlx, &(info.collectibles));
	if (keycode == 124)
		ft_moveright(mlx, &(info.collectibles));
	if (keycode == 123)
		ft_moveleft(mlx, &(info.collectibles));
	else if (keycode == 53)
		ft_close(mlx);
	ft_put_images(*mlx);
	return (0);
}

void	ft_game(char **map)
{
	t_game		mlx;
	t_data_map	info;

	mlx.counter = 0;
	mlx.map = map;
	info = ft_rcol(map);
	mlx.mlx_init = mlx_init();
	mlx.mlx_window = mlx_new_window(mlx.mlx_init, (info.col + 1) * 80, (info.r
				+ 1) * 80, "so_long");
	ft_import_images(&mlx);
	ft_put_images(mlx);
	mlx_hook(mlx.mlx_window, 2, 1L << 0, ft_move, &mlx);
	mlx_hook(mlx.mlx_window, 17, 1L << 0, ft_close, &mlx);
	mlx_loop(mlx.mlx_init);
}
