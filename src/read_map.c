/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:27:25 by lkilpela          #+#    #+#             */
/*   Updated: 2024/02/05 11:40:05 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line_width(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

static int	add_to_map(t_game *game, char *line)
{
	int		i;
	char	**new_arr;

	i = 0;
	if (game->map.height == 0)
		game->map.width = get_line_width(line);
	else if (game->map.width != get_line_width(line))
		return (ERROR_INVALID_MAP_FILE);
	new_arr = malloc(sizeof(char *) * (game->map.height + 1));
	if (!new_arr)
		return (ERROR_ALLOCATING_MEMORY);
	while (i < game->map.height)
	{
		new_arr[i] = game->map.grid[i];
		i++;
	}
	new_arr[game->map.height++] = line;
	free(game->map.grid);
	game->map.grid = new_arr;
	return (0);
}

// status error : invalid map or memory allocation
int	load_map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ERROR_OPENING_FILE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		status = add_to_map(game, line);
		if (status < 0)
		{
			free(line);
			close(fd);
			return (status);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (validate_map(game));
}
