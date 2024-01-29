/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:51:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/29 15:00:53 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*g_error_msgs[] = {
	"No error.",
	"Error: Null argument provided.",
	"Error: Opening file.",
	"Error: Allocating memory for map grid.",
	"Error: Reading map file.",
	"Error: Invalid map. The provided map is not in valid form.",
	"Error: Empty map.",
	"Error: Invalid character in map.",
	"Error: Invalid map dimensions.",
	"Error: Invalid map boundary. The map should be surrounded by walls.",
	"Error: Invalid player count. The map should contain exactly one player.",
	"Error: Invalid exit count. The map should contain at least one exit.",
	"Error: No file provided. Please provide a .ber file as the 1st	argument.",
	"Error: Invalid file. The map file must have a .ber extension.",
	"Error: Invalid map. No player found in the map.",
	"Error: Invalid map. No exit found in the map.",
	"Error: Invalid map. No collectible found in the map.",
	"Error: Failed to load one or more game textures.",
	"Error: Invalid map path."
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
		printf("[%d] %s\n", err, g_error_msgs[-err]);
	else
		printf("Unknown error\n");
	exit(EXIT_FAILURE);
}