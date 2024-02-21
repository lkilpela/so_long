/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/02/21 09:26:59 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_position	make_pos(int x, int y)
{
	t_position pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

static int	step(t_game *game, char	*new_arr, t_position pos, char element)
{
	int		i;

	i = pos.y * game->map.width + pos.x;
	if (game->map.grid[pos.y][pos.x] == element)
		return (1);
	if (new_arr[i] || game->map.grid[pos.y][pos.x] == WALL
		|| game->map.grid[pos.y][pos.x] == EXIT)
		return (0);
	new_arr[i] = 1;
	return (step(game, new_arr, make_pos(pos.x - 1, pos.y), element)
		|| step(game, new_arr, make_pos(pos.x + 1, pos.y), element)
		|| step(game, new_arr, make_pos(pos.x, pos.y - 1), element)
		|| step(game, new_arr, make_pos(pos.x, pos.y + 1), element));
}

int	validate_path(t_game *game, char element)
{
	char	*new_arr;
	int		res;

	new_arr = malloc(sizeof(char) * (game->map.width * game->map.height));
	if (!new_arr)
		return (ERROR_ALLOCATING_MEMORY);
	ft_memset(new_arr, 0, game->map.width * game->map.height);
	res = step(game, new_arr, game->player, element);
	free(new_arr);
	if (res == 0)
		return (ERROR_INVALID_PATH);
	return (0);
}
