/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 17:31:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "MLX42/include/MLX42/MLX42.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define TILE_SIZE 64

typedef struct	s_position
{
	int	x;
	int	y;
}				t_position; 

typedef struct	s_map
{
	char 		**grid;
	int			width;
	int			height;
	//int			collectibles;
	//int			player;
	//t_position	exit;
	//t_position	player_pos;
}
				t_map;
				
typedef struct	s_tiles
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
	void	*player;
}				t_tiles;

typedef struct	s_game
{
	int			collectibles_count;
	int			move_count;
	t_map		map;
	t_position	player;
	t_position	exit;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
}
				t_game;

int	load_map(t_map *map, char *map_file);

#endif