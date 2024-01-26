/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/26 09:01:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_player_movement(t_game *game, int move_x, int move_y)
{
	int	new_y;
	int	new_x;

	new_y = game->player.y + move_y;
	new_x = game->player.x + move_x;
	if (game->map.grid[new_y][new_x] != WALL)
	{
		game->tiles.player->instances[0].y += move_y * game->tile_size;
		game->tiles.player->instances[0].x += move_x * game->tile_size;
		new_y++;
		new_x++;
		game->move_count++;
		printf("Number of movements: %d\n", game->move_count);
	}
}

static void	handle_game_interaction(t_game *game)
{
	int		player_pos;
	bool	is_same_x;
	bool	is_same_y;
	size_t	i;

	player_pos = game->map.grid[game->player.y][game->player.x];
	is_same_x = game->tiles.collectible->instances[i].x == game->player.x * game->tile_size;
	is_same_y = game->tiles.collectible->instances[i].y == game->player.y * game->tile_size;
	if (player_pos == COLLECTIBLE)
	{
		i = 0;
		while (i < game->tiles.collectible->count)
		{
			if (is_same_x && is_same_x)
			{
				if (game->tiles.collectible->instances[i].enabled)
				{
					game->collectibles_count++;
					printf("Heart collected: %d\n", game->collectibles_count);
					game->tiles.collectible->instances[i].enabled = 0;
				}
			}
			++i;
		}
	}
	if (player_pos == EXIT)
	{
		printf("Congratulations, You Win!!!\n");
		mlx_close_window(game->mlx_ptr);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		move_x;
	int		move_y;

	move_x = 0;
	move_y = 0;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx_ptr);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_y = -1;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_y = 1;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_x = -1;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_x = 1;
	if (move_x != 0 || move_y != 0)
	{
		handle_player_movement(game, move_x, move_y);
		handle_game_interaction(game);
	}
}

void	init_player_movement(t_game *game)
{
	mlx_key_hook(game->mlx_ptr, key_hook, game);
}
