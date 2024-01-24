#include "so_long.h"

static void	check_argument(int argc, char **argv)
{
	char	*filename;
	char	*extension;
	int		len;

	if (argc != 2)
	{
		print_error(ERROR_NO_MAP_FILE);
		exit (ERROR_NO_MAP_FILE);
	}
	filename = argv[1];
	len = ft_strlen(filename);
	extension = ft_strnstr(filename, ".ber", len);
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
	{
		print_error(ERROR_INVALID_MAP_FILE);
		exit (ERROR_INVALID_MAP_FILE);
	}
}
void    free_game(t_game *game)
{
	int y;

	y = 0;
	while (y < game->map.height)
	{
		free(game->map.grid[y]);
		y++;
	}
	free(game->map.grid);
}

int	main(int argc, char **argv)
{
	t_game	game;
	mlx_t	*mlx;
	int		status;

	check_argument(argc, argv);
	mlx = mlx_init(MAX_DIMENSION, MAX_DIMENSION, "so_long", true);
	if (!mlx)
		ft_error();
	game.mlx_ptr = mlx;
	if ((status = init_game(&game, argv[1])) < 0)
	{
		print_error(status);
		return (status);
	}
	init_player_movement(&game);	
	render(&game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (EXIT_SUCCESS);
}
