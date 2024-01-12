/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:08:22 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/11 15:52:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_next_line.h"

t_map	*load_map(char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	char	*array[MAX_MAP_HEIGHT];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	x = 0;
	y = 0;
	while ((line = get_next_line(fd)))
	{
		x = ft_strlen(line);
		array[y] = line;
		if (x == 0 || x > MAX_MAP_WIDTH || y >= MAX_MAP_HEIGHT)
		{
			while (y >= 0)
			{
				free(array[y]);
				y--;
			}
			close(fd);
			return (NULL);
		}
		y++;
	}
}
