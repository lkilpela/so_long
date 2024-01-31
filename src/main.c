/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:44:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/31 15:10:51 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_argument(int argc, char **argv)
{
	char	*filename;
	int		len;

	if (argc != 2)
	{
		print_error (ERROR_NO_MAP_FILE);
		exit (EXIT_FAILURE);
	}
	filename = argv[1];
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp((filename + len - 4), ".ber", 4) != 0)
	{
		print_error(ERROR_INVALID_MAP_FILE);
		exit (EXIT_FAILURE);
	}
}

static void	init_game_state(t_game *game)
{
	game->collectibles_count = 0;
	game->move_count = 0;
	game->map.grid = 0;
	game->map.height = 0;
	game->map.width = 0;
	game->map.collectibles = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->player.x = 0;
	game->player.y = 0;
}

static void	init_player_movement(t_game *game)
{
	mlx_key_hook(game->mlx_ptr, key_hook, game);
}

static void	free_game(t_game *game)
{
	int	y;

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
	int		status;

	check_argument(argc, argv);
	init_game_state(&game);
	status = load_map(&game, argv[1]);
	if (status < 0)
		print_error (status);
	calculate_tile_size(&game, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.mlx_ptr = mlx_init(game.tile_size * game.map.width,
			game.tile_size * game.map.height, "so_long", true);
	if (!game.mlx_ptr)
		ft_error();
	status = prepare_game_state(&game);
	if (status < 0)
		print_error (status);
	render(&game);
	init_player_movement(&game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	mlx_terminate(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
