/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 10:01:30 by lkilpela         ###   ########.fr       */
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
	int i;
	int fd;
	int	height;
	
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (-1);
	}
	height = get_next_line(fd, &map_file);
	while (height > 0)
		i++;
	if (height < 0)
	{
		perror("Error reading file\n");
		close(fd);
		return (-1);
	}
	close(fd);
	return (i);
}

int	load_map(t_map *map, char *map_file)
{
	map->row = get_map_height(map_file);
	if(map->row < 0)
	{
		perror("Error");
		return (-1);
	}
	map->column = get_map_width(map_file)
	if(map->column < 0)
	{
		perror("Error");
		return (-1);
	}
	alloc_map_grid(map);
}

void	alloc_map_grid(t_map *map)
{
	int	i;
	
	map->grid = malloc(sizeof(char *) * map->row);
	if (map->grid == NULL)
		exit(-1);
	i = 0;
	while(i < map->row)
	{
		map->grid[i] = malloc(sizeof(char) * map->column);
		if (map->grid == NULL)
			exit(-1);
		i++;
	}
}

int	load_map_grid(t_map *map, char *map_file)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (-1);
	}
	i = 0;
	while (i < map->row)
	{
		j = 0;
		get_next_line(fd, &line);
		while (j < map->column)
		{
			map->grid[i][j] = line[j];
			j++;
		}
		i++;
	}
	close(fd);
	return (0);	
}