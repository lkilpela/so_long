/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 15:45:18 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_texture(t_game *game)
{
	mlx_texture_t	*apple;
	mlx_texture_t	*castledoor;
	mlx_texture_t	*fox;
	mlx_texture_t	*tree;
	mlx_texture_t	*floor;

	apple = mlx_load_png("assets/collectible.png");
	castledoor = mlx_load_png("assets/exit.png");
	fox = mlx_load_png("assets/player.png");
	tree = mlx_load_png("assets/wall.png");
	floor = mlx_load_png("assets/floor.png");
	if (!apple || !castledoor || !fox || !tree || !floor)
		return (ERROR_LOAD_TEXTURE);
	game->tiles.collectible = mlx_texture_to_image(game->mlx_ptr, apple);
	game->tiles.exit = mlx_texture_to_image(game->mlx_ptr, castledoor);
	game->tiles.player = mlx_texture_to_image(game->mlx_ptr, fox);
	game->tiles.wall = mlx_texture_to_image(game->mlx_ptr, tree);
	game->tiles.floor = mlx_texture_to_image(game->mlx_ptr, floor);
	return (0);
}

static void	resize_game_tiles(t_game *game)
{
	int	tile_width;
	int	tile_height;

	tile_width = MAX_DIMENSION / game->map.width;
	tile_height = MAX_DIMENSION / game->map.height;
	if (tile_width < tile_height)
		game->tile_size = tile_width;
	else
		game->tile_size = tile_height;
	mlx_resize_image(game->tiles.collectible, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.exit, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.player, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.wall, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.floor, game->tile_size, game->tile_size);
}

int	init_game(t_game *game, char *map_file)
{
	int	status;

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
	status = load_texture(game);
	if (status < 0)
		return (status);
	status = load_map(game, map_file);
	if (status < 0)
		return (status);
	status = validate_map(game);
	if (status < 0)
		return (status);
	resize_game_tiles(game);
	return (0);
}
