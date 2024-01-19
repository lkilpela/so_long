#include "srcs/so_long.h"



// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

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
		
	// Create and display the image.
	//mlx_image_t* img = mlx_new_image(mlx, 256, 256);
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
	//if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	//	ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	//mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
