/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/23 21:40:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
/*
static int	open_map_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror(ERROR_OPENING_FILE_MSG);
		return (ERROR_OPENING_FILE);
	}
	return (fd);
}

static int	get_map_dimension(t_map *map, int fd)
{
	int		i;
	char	chr;
	
	i = 0;
	map->height = 0;
	while (read(fd, &chr, 1) > 0)
	{
		if (chr == '\n')
		{
			map->height++;
			if(map->height == 1)
				map->width = i;
			else if(i != map->width)
				return (ERROR_INVALID_MAP);
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

static int	allocate_map_grid(t_map *map)
{
	int	i;
	
	map->grid = malloc(sizeof(char *) * map->height);
	if (map->grid == NULL)
		return (ERROR_ALLOCATING_MEMORY);
	i = 0;
	while(i < map->height)
	{
		map->grid[i] = malloc(sizeof(char) * (map->width + 1));
		if (map->grid[i] == NULL)
		{
			while (i >= 0)
				free(map->grid[i--]);
			free(map->grid);
			map->grid = NULL;
			return (ERROR_ALLOCATING_MEMORY);
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
		perror(ERROR_EMPTY_MAP_MSG);
		return (ERROR_EMPTY_MAP);
	}
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			chr = map->grid[i][j];
			if (chr != OPEN_SPACE && chr != WALL && chr != COLLECTIBLE 
				&& chr != EXIT && chr != PLAYER)
			{
				printf("Invalid character '%c' at position (%d, %d)\n", chr, i, j);
				return (ERROR_INVALID_CHARACTER);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int read_map_into_struct(t_map *map, int fd)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (read(fd, map->grid[i], map->width + 1) < 0)
		{
			perror(ERROR_READING_FILE_MSG);
			close(fd);
			return (ERROR_READING_FILE);
		}
		map->grid[i][map->width] = '\0';
		i++;
	}
	close(fd);
	return (0);	
}

int	load_map(t_map *map, char *map_file)
{
	int fd;

	fd = open_map_file(map_file);
	if (get_map_dimension(map, fd) < 0)
	{
		perror(ERROR_INVALID_DIMENSIONS_MSG);
		return (ERROR_INVALID_DIMENSIONS);
	}
	if (allocate_map_grid(map) < 0)
	{
		perror(ERROR_ALLOCATING_MEMORY_MSG);
		return (ERROR_ALLOCATING_MEMORY);
	}
	if (read_map_into_struct(map, fd) < 0)
	{
		perror(ERROR_READING_FILE_MSG);
		return (ERROR_READING_FILE);
	}
	if (validate_map(map) < 0)
	{
		perror(ERROR_INVALID_MAP_MSG);
		return (ERROR_INVALID_MAP);
	}
	return (0);	
}
*/