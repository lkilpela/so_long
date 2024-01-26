/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:44:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/26 14:02:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_argument(int argc, char **argv)
{
	char	*filename;
	char	*extension;
	int		len;

	if (argc != 2)
	{
		print_error (ERROR_NO_MAP_FILE);
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

void	free_game(t_game *game)
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
	{
		print_error (status);
		return (status);
	}
	game.mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", true);
	if (!game.mlx_ptr)
		ft_error();
	render(&game);
	status = prepare_game_state(&game, argv[1]);
	if (status < 0)
	{
		print_error (status);
		return (status);
	}
	init_player_movement(&game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
	mlx_terminate(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
