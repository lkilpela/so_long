/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 10:55:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Calculate width of map, excluding '\n' character as last character in string 
static int	get_map_width(char *map_file)
{
	int	i;

	i = 0;
	while(map_file[i])
		i++;
	if(i > 0 && map_file[i - 1] == '\n')
		i--;
	return (i);
}

//Calculate the number of lines in map file
static int	get_map_height(char *map_file)
{
	int 	i;
	int 	fd;
	char	chr;
	
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (-1);
	}
	while (read(fd, &chr, 1) > 0)
	{
		if (chr == '\n')
			i++;
	}
	close(fd);
	return (i);
}

int	allocate_map(t_map *map, char *map_file)
{
	map->row = get_map_height(map_file);
	map->column = get_map_width(map_file)
	if(map->column < 0 || map->row < 0)
	{
		perror("Error getting map dimensions\n");
		return (-1);
	}
	alloc_map_grid(map);
}

void	allocate_map_grid(t_map *map)
{
	int	i;
	int j;
	
	map->grid = malloc(sizeof(char *) * map->row);
	if (map->grid == NULL)
	{
		perror("Error allocating memory for map grid\n");
		free(map);
		return (-1);
	}
	i = 0;
	while(i++ < map->row)
	{
		map->grid[i] = malloc(sizeof(char) * (map->column + 1));
		if (map->grid[i] == NULL)
		{
			perror("Error allocating memory for map grid\n");
			j = 0;
			while (j < i)
				free(map->grid[j++]);
			free(map->grid);
			free(map);
			return (-1);
		}
	}
}
