// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();

	/* Do stuff */
	mlx_texture_t* apple = mlx_load_png("game_images/apple.png");
	mlx_texture_t* castledoor = mlx_load_png("game_images/castledoor.png");
	mlx_texture_t* cherry = mlx_load_png("game_images/cherry.png");
	mlx_texture_t* fox = mlx_load_png("game_images/fox.png");
	mlx_texture_t* tree = mlx_load_png("game_images/tree.png");
	mlx_texture_t* tile = mlx_load_png("game_images/tiles_0.1.png");

	if(!apple)
		ft_error();
	// Create an image from a texture.
	mlx_image_t* img = mlx_texture_to_image(mlx, apple);
	// Create and display the image.
	//mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_delete_texture(apple);
	mlx_delete_texture(castledoor);
	mlx_delete_texture(cherry);
	mlx_delete_texture(fox);
	mlx_delete_texture(tree);
	mlx_delete_texture(tile);
	return (EXIT_SUCCESS);
}