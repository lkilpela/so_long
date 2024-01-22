/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/22 09:12:39 by lkilpela         ###   ########.fr       */
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
# define WIDTH 1024
# define HEIGHT 1024

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
}
				t_map;
				
typedef struct	s_tiles
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}				t_tiles;

typedef struct	s_game
{
	int			collectibles_count;
	int			move_count;
	t_map		map;
	t_position	player;
	t_position	exit;
	mlx_t		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	int			tile_size;
}
				t_game;

int		load_map(t_map *map, char *map_file);
int		init_game(t_game *game, char *map_file);
void	free_game(t_game *game);
void	ft_error(void);
void	init_player_movement(t_game *game);
void	draw_map(t_game *game);


#endif