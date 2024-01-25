/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/25 14:54:10 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_player_movement(t_game *game, int move_x, int move_y)
{
	if(game->map.grid[game->player.y + dy][game->player.x + dx] != WALL) 
		{
			game->tiles.player->instances[0].y += dy*game->tile_size;
			game->tiles.player->instances[0].x += dx*game->tile_size;
			game->player.y += dy;
			game->player.x += dx;
			game->move_count++;
			printf("Number of movements: %d\n", game->move_count);
		}
}

static void	handle_game_interaction(t_game *game)
{
	 if (game->map.grid[game->player.y][game->player.x] == COLLECTIBLE)
	{
		size_t i = 0;
		while (i < game->tiles.collectible->count) 
		{
			if (game->tiles.collectible->instances[i].x == game->player.x*game->tile_size &&
				game->tiles.collectible->instances[i].y == game->player.y*game->tile_size) 
			{
				if (game->tiles.collectible->instances[i].enabled)
				{
					game->collectibles_count++;
					printf("Collectibles found: %d\n", game->collectibles_count);
					game->tiles.collectible->instances[i].enabled = 0;
				}
			}
			++i;
		}
	}
	if (game->map.grid[game->player.y][game->player.x] == EXIT)
	{		
		printf("Congratulations, you found exit\n");
		mlx_close_window(game->mlx_ptr);
	}	
}

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_game*	game;
	int		move_x;
	int		move_y;

	move_x = 0;
	move_y = =;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
	{
		mlx_close_window(game->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		move_y = -1;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_y = 1;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_x = -1;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_x = 1;
	if(move_x != 0 || move_y != 0) 
	{
		handle_player_movement(game, move_x, move_y);
		handle_game_interaction(game);
	}
}

void init_player_movement(t_game *game)
{
    mlx_key_hook(game->mlx_ptr, key_hook, game);
}
