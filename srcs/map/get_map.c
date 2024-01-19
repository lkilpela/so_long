/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 13:05:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_dimension(t_map *map, char *map_file)
{
	int		i;
	int 	fd;
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

static int	allocate_map(t_map *map, char *map_file)
{
	map->row = get_map_height(map_file);
	map->column = get_map_width(map_file)
	if(map->column < 0 || map->row < 0)
	{
		perror("Error getting map dimensions\n");
		return (-1);
	}
	alloc_map_grid(map);
	if (map->grid == NULL)
	{
		perror("Error allocating memory for map grid\n");
		return (-1);
	}
	return (0);
}

static void	allocate_map_grid(t_map *map)
{
	int	i;
	int j;
	
	map->grid = malloc(sizeof(char *) * map->row);
	if (map->grid == NULL)
	{
		perror("Error allocating memory for map grid\n");
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
			return (-1);
		}
	}
}

int	validate_map(t_map *map)
{
	int	i;

	i = 0;
	if(map->row == 0 || map->column == 0)
	{
		perror("Error: Map is empty\n");
		return (-1);
	}
	while (i++ < map->row)
	{
		if ()
	}
	
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
	while (i++ < map->row)
	{
		if (read(fd, map->grid[i], map->column + 1) < 0)
		{
			perror("Error reading map file\n");
			close(fd);
			return (-1);
		}
		map->grid[i][map->column] = '\0';
	}
	close(fd);
	return (0);	
}
