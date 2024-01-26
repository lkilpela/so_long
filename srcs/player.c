/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/26 14:25:12 by lkilpela         ###   ########.fr       */
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
		game->player.y = new_y;
		game->player.x = new_x;
		game->move_count++;
		printf("Number of movements: %d\n", game->move_count);
	}
}

static void	handle_collectibles(t_game *game)
{
	size_t	i;

	if (game->map.grid[game->player.y][game->player.x] == COLLECTIBLE)
	{
		i = 0;
		while (i < game->tiles.collectible->count)
		{
			if (game->tiles.collectible->instances[i].x
				== game->player.x * game->tile_size
				&& game->tiles.collectible->instances[i].y
				== game->player.y * game->tile_size)
			{
				if (game->tiles.collectible->instances[i].enabled)
				{
					game->collectibles_count++;
					printf("Heart collected: %d\n", game->collectibles_count);
					game->tiles.collectible->instances[i].enabled = 0;
				}
			}
			i++;
		}
	}
}

static void	handle_exit(t_game *game)
{
	if (game->map.grid[game->player.y][game->player.x] == EXIT)
	{
		printf("Congratulations, you exited!!!\n");
		printf("Number of hearts collected: %d/%d\n",game->collectibles_count, game->map.collectibles);
		mlx_close_window(game->mlx_ptr);
	}
}

static void	check_keys(mlx_key_data_t keydata, int *move_x, int *move_y)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		*move_y = -1;
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		*move_y = 1;
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		*move_x = -1;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		*move_x = 1;
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
	{
		printf("Player pressed ESC. Closing the game...\n");
		printf("Number of hearts collected: %d/%d\n",game->collectibles_count, game->map.collectibles);
		mlx_close_window(game->mlx_ptr);
	}
	check_keys(keydata, &move_x, &move_y);
	if (move_x != 0 || move_y != 0)
	{
		handle_player_movement(game, move_x, move_y);
		handle_collectibles(game);
		handle_exit(game);
	}
}
