/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/29 14:17:56 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	step(t_game *game, char *new_arr, int x, int y)
{
	int	i;

	i = y * game->map.width + x;
	if (new_arr[i] || game->map.grid[y][x] == WALL)
		return (0);
	if (game->map.grid[y][x] == EXIT)
		return (1);
	new_arr[i] = 1;
	return (step(game, new_arr, x - 1, y) || step(game, new_arr, x + 1, y)
		|| step(game, new_arr, x, y - 1) || step(game, new_arr, x, y + 1));
}

int	validate_path(t_game *game)
{
	char	*new_arr;
	int		res;

	new_arr = malloc(sizeof(char) * (game->map.width * game->map.height));
	if (!new_arr)
		return (ERROR_ALLOCATING_MEMORY);
	ft_memset(new_arr, 0, game->map.width * game->map.height);
	res = step(game, new_arr, game->player.x, game->player.y);
	free(new_arr);
	if (res == 0)
		return (ERROR_INVALID_PATH);
}
