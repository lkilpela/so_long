/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/16 21:12:56 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point; 

typedef struct	s_map
{
	char 	**map;
	int		row;
	int		column;
	int		collectibles;
	int		player;
	int		exit;
	t_point	player_pos;
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
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_tiles	tiles;
	int		moves;
}
				t_game;

#endif