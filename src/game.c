/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/29 11:12:39 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game_textures(t_game *game)
{
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;

	collectible = mlx_load_png("textures/collectible.png");
	exit = mlx_load_png("textures/exit.png");
	player = mlx_load_png("textures/player.png");
	wall = mlx_load_png("textures/wall.png");
	floor = mlx_load_png("textures/floor.png");
	if (!collectible || !exit || !player || !wall || !floor)
		return (ERROR_LOAD_TEXTURE);
	game->tiles.collectible = mlx_texture_to_image(game->mlx_ptr, collectible);
	game->tiles.exit = mlx_texture_to_image(game->mlx_ptr, exit);
	game->tiles.player = mlx_texture_to_image(game->mlx_ptr, player);
	game->tiles.wall = mlx_texture_to_image(game->mlx_ptr, wall);
	game->tiles.floor = mlx_texture_to_image(game->mlx_ptr, floor);
	mlx_delete_texture(collectible);
	mlx_delete_texture(exit);
	mlx_delete_texture(player);
	mlx_delete_texture(wall);
	mlx_delete_texture(floor);
	return (0);
}

void	calculate_tile_size(t_game *game, int width, int height)
{
	int	tile_width;
	int	tile_height;

	tile_width = width / game->map.width;
	tile_height = height / game->map.height;
	if (tile_width < tile_height)
		game->tile_size = tile_width;
	else
		game->tile_size = tile_height;
}

static void	resize_game_tiles(t_game *game, int width, int height)
{
	calculate_tile_size(game, width, height);
	mlx_resize_image(game->tiles.collectible, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.exit, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.player, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.wall, game->tile_size, game->tile_size);
	mlx_resize_image(game->tiles.floor, game->tile_size, game->tile_size);
}

static void	resize_window(int width, int height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx_ptr, game->tiles.collectible);
	mlx_delete_image(game->mlx_ptr, game->tiles.exit);
	mlx_delete_image(game->mlx_ptr, game->tiles.player);
	mlx_delete_image(game->mlx_ptr, game->tiles.wall);
	mlx_delete_image(game->mlx_ptr, game->tiles.floor);
	init_game_textures(game);
	resize_game_tiles(game, width, height);
	render(game);
}

int	prepare_game_state(t_game *game)
{
	int	status;

	status = init_game_textures(game);
	if (status < 0)
		return (status);
	resize_game_tiles(game, game->mlx_ptr->width, game->mlx_ptr->height);
	mlx_resize_hook(game->mlx_ptr, resize_window, game);
	return (0);
}
