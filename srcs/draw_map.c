/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:40:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 09:15:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_tile(t_game *game, int j, int i)
{
	if(game->map.grid[i][j] == 'C')
		return (game->tiles.collectible);
	if(game->map.grid[i][j] == 'E')
		return (game->tiles.exit);
	if(game->map.grid[i][j] == 'P')
		return (game->tiles.player);
	return NULL;
}

static void* get_basic_tile(t_game* game, int x, int y) 
{
	if(game->map.grid[y][x] == '1')
		return (game->tiles.wall);
	return (game->tiles.floor);
}

void draw_map(t_game *game)
{
	int i = 0;
	while (i < game->map.height)
	{
		int j = 0;
		while (j < game->map.width)
		{
			mlx_image_to_window(game->mlx_ptr, get_basic_tile(game, j, i), game->tile_size * j, game->tile_size * i);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		int j = 0;
		while (j < game->map.width)
		{
			void* tile = get_tile(game, j, i);
			if(tile) 
				mlx_image_to_window(game->mlx_ptr, tile, game->tile_size * j, game->tile_size * i);
			j++;
		}
		i++;
	}
}

