#include "srcs/so_long.h"


//void	hook(void *param)
//{
//	t_game* game = param;

	// Print the window width and height.
	//printf("WIDTH: %d | HEIGHT: %d\n", game->mlx_ptr->width, game->mlx_ptr->height);
//}
int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (0);
	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_error();

	game.mlx_ptr = mlx;
	if (init_game(&game, argv[1]) < 0)
	{
		perror("Error");
		return (-1);
	}
	init_player_movement(&game);	
	draw_map(&game);
//	mlx_loop_hook(game.mlx_ptr, hook, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
