/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:33:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/18 22:17:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_ber_extension(char *map_file)
{
	char	*dot;

	dot = ft_strrchr(map_file, '.');
	if (!dot || ft_strcmp(dot, ".ber"))
		return (false);
	return (true);
}

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