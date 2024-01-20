/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/20 17:37:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	hook(void *param)
{
	t_game* game = param;

	// Print the window width and height.
	printf("WIDTH: %d | HEIGHT: %d\n", game->mlx_ptr->width, game->mlx_ptr->height);

	static int left_state;

	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx_ptr);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_UP))
		game->tiles.player->instances[0].y -= TILE_SIZE;fvgFY B
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_DOWN))
		game->tiles.player->instances[0].y += TILE_SIZE;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_LEFT)) {      
		if(!left_state) game->tiles.player->instances[0].x -= TILE_SIZE;
		left_state = 1;
	} else left_state = 0;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_RIGHT))
		game->tiles.player->instances[0].x += TILE_SIZE;
}*/



void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_game* game = param;
	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx_ptr);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		game->tiles.player->instances[0].y -= TILE_SIZE;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		game->tiles.player->instances[0].y += TILE_SIZE;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->tiles.player->instances[0].x -= TILE_SIZE;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->tiles.player->instances[0].x += TILE_SIZE;
}


void init_player_movement(t_game *game)
{
    mlx_key_hook(game->mlx_ptr, key_hook, game);
}