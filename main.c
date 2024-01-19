// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "srcs/so_long.h"
#include "MLX42/MLX42.h"
#define WIDTH 1024
#define HEIGHT 1024

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();

	/* Do stuff */
	mlx_texture_t* apple = mlx_load_png("assets/item.png");
	mlx_texture_t* castledoor = mlx_load_png("assets/exit.png");
	mlx_texture_t* fox = mlx_load_png("assets/player.png");
	mlx_texture_t* tree = mlx_load_png("assets/wall.png");
	mlx_texture_t* tile = mlx_load_png("assets/floor.png");

	if(!apple || !castledoor || !fox || !tree || !tile)
		ft_error();
	// Create an image from a texture.
	t_game game;
	game.tiles.collectible = mlx_texture_to_image(mlx, apple);
	mlx_resize_image(game.tiles.collectible, TILE_SIZE, TILE_SIZE);
	game.tiles.exit = mlx_texture_to_image(mlx, castledoor);
	mlx_resize_image(game.tiles.exit, TILE_SIZE, TILE_SIZE);
	game.tiles.player = mlx_texture_to_image(mlx, fox);
	mlx_resize_image(game.tiles.player, TILE_SIZE, TILE_SIZE);
	game.tiles.wall = mlx_texture_to_image(mlx, tree);
	mlx_resize_image(game.tiles.wall, TILE_SIZE, TILE_SIZE);
	game.tiles.floor = mlx_texture_to_image(mlx, tile);
	mlx_resize_image(game.tiles.floor, TILE_SIZE, TILE_SIZE);

	if (load_map(&game.map, "game_maps/map.ber") < 0) 
	{
		fprintf(stderr, "Error loading map\n");
		return 1;
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
	mlx_delete_texture(apple);
	mlx_delete_texture(castledoor);
	mlx_delete_texture(fox);
	mlx_delete_texture(tree);
	mlx_delete_texture(tile);
	return (EXIT_SUCCESS);
}
