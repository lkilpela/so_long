/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 12:50:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *(*get_tile_func)(t_game *, int, int);

static void	*get_tile(t_game *game, int x, int y)
{
	if (!game)
		return (NULL);
	if (game->map.grid[y][x] == COLLECTIBLE)
		return (game->tiles.collectible);
	if (game->map.grid[y][x] == EXIT)
		return (game->tiles.exit);
	if (game->map.grid[y][x] == PLAYER)
		return (game->tiles.player);
	return (NULL);
}

static void	*get_basic_tile(t_game *game, int x, int y)
{
	if (!game)
		return (NULL);
	if (game->map.grid[y][x] == WALL)
		return (game->tiles.wall);
	return (game->tiles.floor);
}

void	draw_tiles(t_game *game, get_tile_func get_tile)
{
	int		x;
	int		y;
	void	*tile;

	if (!game)
		return;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = get_tile(game, x, y);
			if (tile)
				mlx_image_to_window(game->mlx_ptr, tile, game->tile_size * x,
					game->tile_size * y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	if (!game)
		return;
	draw_tiles(game, get_basic_tile);
	draw_tiles(game, get_tile);
}
