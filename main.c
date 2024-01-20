#include "srcs/so_long.h"

static void	*get_tile(t_game *game, int j, int i)
{
	if(game->map.grid[i][j] == '0')
		return (game->tiles.floor);
	if(game->map.grid[i][j] == '1')
		return (game->tiles.wall);
	if(game->map.grid[i][j] == 'C')
		return (game->tiles.collectible);
	if(game->map.grid[i][j] == 'E')
		return (game->tiles.exit);
	if(game->map.grid[i][j] == 'P')
		return (game->tiles.player);
	return (game->tiles.wall);
}

int	main(void)
{
	t_game game;

	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();

	game.mlx_ptr = mlx;
	if (init_game(&game, "game_maps/map.ber") < 0)
	{
		perror("Error");
		return (-1);
	}
	init_player_movement(&game);	
	int i = 0;
	while (i < game.map.height)
	{
		int j = 0;
		while (j < game.map.width)
		{
			mlx_image_to_window(mlx, get_tile(&game, j, i), TILE_SIZE * j, TILE_SIZE * i);
			j++;
		}
		i++;
	}
	
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
