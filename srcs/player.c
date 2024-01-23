/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/23 22:16:41 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_game* game = param;
	int dx = 0, dy = 0;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
	{
		mlx_close_window(game->mlx_ptr);
		return;
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		dy = -1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		dy = 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		dx = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		dx = 1;
	if(dx != 0 || dy != 0) 
	{
		if(game->map.grid[game->player.y + dy][game->player.x + dx] != '1') 
		{
			game->tiles.player->instances[0].y += dy*game->tile_size;
			game->tiles.player->instances[0].x += dx*game->tile_size;
			game->player.y += dy;
			game->player.x += dx;
			game->move_count++;
			if(game->map.grid[game->player.y][game->player.x] == 'C') 
			{
				size_t i = 0;
				while(i < game->tiles.collectible->count) {
					if(game->tiles.collectible->instances[i].x == game->player.x*game->tile_size &&
						game->tiles.collectible->instances[i].y == game->player.y*game->tile_size) 
					{
						if(game->tiles.collectible->instances[i].enabled) {
							game->collectibles_count++;
							printf("Collectibles found: %d\n", game->collectibles_count);
							game->tiles.collectible->instances[i].enabled = 0;
						}
					}
					++i;
				}
			}	
			printf("Number of movements: %d\n", game->move_count);
			if(game->map.grid[game->player.y][game->player.x] == EXIT) {		
				printf("Congratulations, you found exit\n");
				mlx_close_window(game->mlx_ptr);
			}
		}
	}
}

void init_player_movement(t_game *game)
{
    mlx_key_hook(game->mlx_ptr, key_hook, game);
}
