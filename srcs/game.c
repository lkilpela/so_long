/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:34:51 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 18:06:12 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_game(t_game *game, char *map_file)
{
    mlx_texture_t* apple = mlx_load_png("assets/item.png");
	mlx_texture_t* castledoor = mlx_load_png("assets/exit.png");
	mlx_texture_t* fox = mlx_load_png("assets/player.png");
	mlx_texture_t* tree = mlx_load_png("assets/wall.png");
	mlx_texture_t* tile = mlx_load_png("assets/floor.png");

    if(!apple || !castledoor || !fox || !tree || !tile)
		ft_error();

    game->tiles.collectible = mlx_texture_to_image(game->mlx_ptr, apple);
	mlx_resize_image(game->tiles.collectible, TILE_SIZE, TILE_SIZE);
	game->tiles.exit = mlx_texture_to_image(game->mlx_ptr, castledoor);
	mlx_resize_image(game->tiles.exit, TILE_SIZE, TILE_SIZE);
	game->tiles.player = mlx_texture_to_image(game->mlx_ptr, fox);
	mlx_resize_image(game->tiles.player, TILE_SIZE, TILE_SIZE);
	game->tiles.wall = mlx_texture_to_image(game->mlx_ptr, tree);
	mlx_resize_image(game->tiles.wall, TILE_SIZE, TILE_SIZE);
	game->tiles.floor = mlx_texture_to_image(game->mlx_ptr, tile);
	mlx_resize_image(game->tiles.floor, TILE_SIZE, TILE_SIZE);

	if (load_map(&game->map, map_file) < 0) 
	{
		printf("Error loading map\n");
		return (-1);
	}
    return (init_pos(game));
}

void    free_game(t_game *game)
{
    mlx_delete_texture(game->tiles.collectible);
	mlx_delete_texture(game->tiles.exit);
	mlx_delete_texture(game->tiles.wall);
	mlx_delete_texture(game->tiles.floor);
	mlx_delete_texture(game->tiles.player);
}

int init_pos(t_game *game)
{
    int x;
    int y;
    while (y < game->map.height)
    {
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
        }
    }
    return (0);
}