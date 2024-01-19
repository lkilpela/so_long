/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 14:30:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_dimension(t_map *map, char *map_file)
{
	int		i;
	int		fd;
	char	chr;
	
	i = 0;
	map->height = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (-1);
	}
	while (read(fd, &chr, 1) > 0)
	{
		if (chr == '\n')
		{
			map->height++;
			if(map->height == 1)
				map->width = i;
			else if(i != map->width)
				return (-1);
			i = 0;
		}
		else
			i++;
	}
	close(fd);
	return (0);
}

static int	allocate_map_grid(t_map *map)
{
	int	i;
	int j;
	
	map->grid = malloc(sizeof(char *) * map->height);
	if (map->grid == NULL)
	{
		perror("Error allocating memory for map grid\n");
		return (-1);
	}
	i = 0;
	while(i++ < map->height)
	{
		map->grid[i] = malloc(sizeof(char) * (map->width + 1));
		if (map->grid[i] == NULL)
		{
			perror("Error allocating memory for map grid\n");
			j = 0;
			while (j < i)
				free(map->grid[j++]);
			free(map->grid);
			return (-1);
		}
	}
	return (0);
}

static int	validate_map(t_map *map)
{
	int		i;
	int		j;
	char	chr;

	i = 0;
	if(map->height == 0 || map->width == 0)
	{
		perror("Error: Map is empty\n");
		return (-1);
	}
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			chr = map->grid[i][j];
			if (chr != '0' && chr != '1' && chr != 'C' && chr != 'E' 
			&& chr != 'P')
			{
				printf("Invalid character '%c' at position (%d, %d)\n", chr, i, j);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int read_map_into_struct(t_map *map, char *map_file)
{
	int	fd;
	int	i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (-1);
	}
	i = 0;
	while (i < map->height)
	{
		if (read(fd, map->grid[i], map->width + 1) < 0)
		{
			perror("Error reading map file\n");
			close(fd);
			return (-1);
		}
		map->grid[i][map->width] = '\0';
		i++;
	}
	close(fd);
	return (0);	
}

