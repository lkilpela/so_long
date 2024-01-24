/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:13:47 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/24 14:49:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  check_empty_map(t_game *game)
{
	if (game->map.height == 0 || game->map.width == 0)
		return (ERROR_EMPTY_MAP);
	return (0);
}
static int check_valid_character(t_game *game, int x, int y)
{
	char	c;
	
	c = game->map.grid[y][x];
	if (c != OPEN_SPACE && c != WALL && c != COLLECTIBLE 
		&& c != EXIT && c != PLAYER)
		return (ERROR_INVALID_CHARACTER);
	return (0);
}

static int check_valid_wall(t_game *game, int x, int y)
{
	char	c;
	
	c = game->map.grid[y][x];
	if (y == 0 || y == game->map.height - 1 || x == 0 ||
				x == game->map.width - 1)
	{
		if (c != WALL)
			return (ERROR_INVALID_BOUNDARY);
	}
	return (0);		
}

static int	check_single_player(t_game *game, int x, int y)
{
	char	c;
	
	c = game->map.grid[y][x];
	if (c == PLAYER)
	{
		if (game->player.x == 0 && game->player.y == 0)
		{
			game->player.x = x;
			game->player.y = y;
		}
		else
			return (ERROR_INVALID_PLAYER_COUNT);
	}
	return (0);
}

static int check_exit(t_game *game, int x, int y)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == EXIT)
	{
		if (game->exit.x == 0 && game->exit.y == 0)
		{
			game->exit.x = x;
			game->exit.y = y;
		}
		else
			return (ERROR_INVALID_EXIT_COUNT);
	}
	return (0);
}

static int	check_collectible(t_game *game, int x, int y)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == COLLECTIBLE)
		game->map.collectibles++;
	return (0);
}

int	validate_map(t_game *game)
{
	int	status;
	
	status = check_empty_map(game);
	if (status < 0)
		return (status);
	status = iterate_map(game, check_valid_wall);
	if (status < 0)
		return (status);
	status = iterate_map(game, check_valid_character);
	if (status < 0)
		return (status);
	status = iterate_map(game, check_single_player);
	if (status < 0)
		return (status);
	if (game->player.x == 0 && game->player.y == 0)
		return (ERROR_NO_PLAYER);
	status = iterate_map(game, check_exit);
	if (status < 0)
		return (status);
	if (game->exit.x == 0 && game->exit.y == 0)
		return (ERROR_NO_EXIT);
	iterate_map(game, check_collectible);
	if (game->map.collectibles == 0)
		return (ERROR_NO_COLLECTIBLE);
	return (0);
}
