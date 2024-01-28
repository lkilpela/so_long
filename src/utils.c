/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:51:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/28 17:46:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*g_error_msgs[] = {
	"No error.",
	"Error: Null argument provided.",
	"Error: Opening file.",
	"Error: Allocating memory for map grid.",
	"Error: Reading map file.",
	"Error: Validating map.",
	"Error: Empty map.",
	"Error: Invalid character in map.",
	"Error: Invalid map dimensions.",
	"Error: Invalid map boundary. The map should be surrounded by walls.",
	"Error: Invalid player count. The map should contain exactly one player.",
	"Error: Invalid exit count. The map should contain at least one exit.",
	"Error: No file provided. Please provide a .ber file as the 1st	argument.",
	"Error: Invalid map file. The map file must have a .ber extension.",
	"Error: No player found in the map.",
	"Error: No exit found in the map.",
	"Error: No collectible found in the map.",
	"Error: Failed to load one or more game textures."
};

// Exit the program as failure.
void	ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	print_error(int err)
{
	if (err < 0 && err > LAST_ERROR)
		printf("%s\n", g_error_msgs[-err]);
	else
		printf("Unknown error\n");
}

int	iterate_map(t_game *game, t_tile_function func)
{
	int	x;
	int	y;
	int	status;

	if (!game)
		return (ERROR_NULL_ARGUMENT);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			status = func(game, x, y);
			if (status < 0)
				return (status);
			x++;
		}
		y++;
	}
	return (0);
}
