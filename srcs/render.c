/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:12:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 10:08:28 by lkilpela         ###   ########.fr       */
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

int	iterate_map(t_game *game, tile_function func)
{
	int	x;
	int	y;
	int	status;

	if (!game)
		return;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			status = func(game, x, y);
			if(status < 0)
				return (status);
			x++;
		}
		y++;
	}
	return (0);
}

// Draw the entire game map
void	draw_map(t_game *game)
{
	if (!game)
		return;
	iterate_map(game, draw_basic_tile);
	iterate_map(game, draw_special_tile);
}
