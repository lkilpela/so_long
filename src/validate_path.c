/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/02/21 09:01:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	step(t_game *game, int x, int y, char element)
{
	int		i;
	char	*new_arr;

	i = y * game->map.width + x;
	if (game->map.grid[y][x] == element)
		return (1);
	if (new_arr[i] || game->map.grid[y][x] == WALL
		|| game->map.grid[y][x] == EXIT)
		return (0);
	new_arr[i] = 1;
	return (step(game, new_arr, x - 1, y, element)
		|| step(game, new_arr, x + 1, y, element)
		|| step(game, new_arr, x, y - 1, element)
		|| step(game, new_arr, x, y + 1, element));
}

int	validate_path(t_game *game, char element)
{
	char	*new_arr;
	int		res;

	new_arr = malloc(sizeof(char) * (game->map.width * game->map.height));
	if (!new_arr)
		return (ERROR_ALLOCATING_MEMORY);
	ft_memset(new_arr, 0, game->map.width * game->map.height);
	res = step(game, new_arr, game->player.x, game->player.y, element);
	free(new_arr);
	if (res == 0)
		return (ERROR_INVALID_PATH);
	return (0);
}
