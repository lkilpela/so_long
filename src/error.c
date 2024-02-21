/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:51:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/02/21 10:30:01 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char *get_error_messages(int e)
{
	static const char	*error_messages[] = {
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
	"Error: Invalid exit count. The map should contain one exit.",
	"Error: No file provided. Please provide a .ber file as the 1st argument.",
	"Error: Invalid file. The map file must have a .ber extension.",
	"Error: Invalid map. No player found in the map.",
	"Error: Invalid map. No exit found in the map.",
	"Error: Invalid map. No collectible found in the map.",
	"Error: Failed to load one or more game textures.",
	"Error: Invalid map path.",
	"Error: Empty line in the map."
};
	return (error_messages[e]);
}

const char *valid_error_messages(int e)
{
	if (e >= 0 || e < LAST_ERROR)
		return (get_error_messages(e));
	else
        return ("Unknown error");
}

void	print_error(int e)
{
	const char	*msg;

	msg = valid_error_messages(e);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

// Exit the program as failure.
void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
