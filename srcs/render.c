/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:12:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 15:09:40 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	draw_special_tile(t_game *game, int x, int y)
{
	void	*tile;
	
	tile = NULL;
	if (!game)
		return (-1);
	if (game->map.grid[y][x] == COLLECTIBLE)
		tile = game->tiles.collectible;
	if (game->map.grid[y][x] == EXIT)
		tile = game->tiles.exit;
	if (game->map.grid[y][x] == PLAYER)
		tile = game->tiles.player;
	if (tile)
		mlx_image_to_window(game->mlx_ptr, tile, game->tile_size * x,
			game->tile_size * y);
	return (0);
}

static int	draw_basic_tile(t_game *game, int x, int y)
{
	void	*tile;
	
	if (!game)
		return (-1);
	if (game->map.grid[y][x] == WALL)
		tile = game->tiles.wall;
	else 
		tile = game->tiles.floor;
	mlx_image_to_window(game->mlx_ptr, tile, game->tile_size * x,
			game->tile_size * y);
	return (0);
}

// Draw the entire game map
void	render(t_game *game)
{
	if (!game)
		exit (ERROR_NULL_ARGUMENT);
	iterate_map(game, draw_basic_tile);
	iterate_map(game, draw_special_tile);
}
