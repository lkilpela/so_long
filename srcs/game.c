/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:34:51 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 09:17:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_pos(t_game *game);

int init_game(t_game *game, char *map_file)
{
	game->collectibles_count = 0;
	game->move_count = 0;
	mlx_texture_t* apple = mlx_load_png("assets/item.png");
	mlx_texture_t* castledoor = mlx_load_png("assets/exit.png");
	mlx_texture_t* fox = mlx_load_png("assets/player.png");
	mlx_texture_t* tree = mlx_load_png("assets/wall.png");
	mlx_texture_t* tile = mlx_load_png("assets/floor.png");

	if(!apple || !castledoor || !fox || !tree || !tile)
		ft_error();
	if (load_map(&game->map, map_file) < 0) 
	{
		printf("Error loading map\n");
		return (-1);
	}
	int a = 1024/game->map.width;
	int b = 1024/game->map.height;
	if(a < b) 
		game->tile_size = a;
	else	
		game->tile_size = b;
		game->tiles.collectible = mlx_texture_to_image(game->mlx_ptr, apple);
	mlx_resize_image(game->tiles.collectible, game->tile_size, game->tile_size);
	game->tiles.exit = mlx_texture_to_image(game->mlx_ptr, castledoor);
	mlx_resize_image(game->tiles.exit, game->tile_size, game->tile_size);
	game->tiles.player = mlx_texture_to_image(game->mlx_ptr, fox);
	mlx_resize_image(game->tiles.player, game->tile_size, game->tile_size);
	game->tiles.wall = mlx_texture_to_image(game->mlx_ptr, tree);
	mlx_resize_image(game->tiles.wall, game->tile_size, game->tile_size);
	game->tiles.floor = mlx_texture_to_image(game->mlx_ptr, tile);
	mlx_resize_image(game->tiles.floor, game->tile_size, game->tile_size);
	return (init_pos(game));
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

int init_pos(t_game *game)
{
	int x;
	int y;

	game->player.x = 0;
	game->player.y = 0;	
	y = 0;
	while (y < game->map.height)
	{
		printf("%d: %s\n", y, game->map.grid[y]);
		x = 0;
		while (x < game->map.width)
		{
			if(game->map.grid[y][x] == 'P') 
			{
				game->player.x = x;
				game->player.y = y;
			}
			if(game->map.grid[y][x] == 'E') 
			{
				game->exit.x = x;
				game->exit.y = y;
			}
			x++;
		}
		y++;
	}
	printf("player at position (%d, %d)\n", game->player.x, game->player.y);
	return (0);
	}