/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/23 22:00:21 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function pointer type declaration. 
typedef int (*tile_function)(t_game *, int, int);

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

void	iterate_map(t_game *game, tile_function func)
{
	int		x;
	int		y;

	if (!game)
		return;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if(func(game, x, y) < 0)
				return;
			x++;
		}
		y++;
	}
}

// Draw the entire game map
void	draw_map(t_game *game)
{
	if (!game)
		return;
	iterate_map(game, draw_basic_tile);
	iterate_map(game, draw_special_tile);
}
