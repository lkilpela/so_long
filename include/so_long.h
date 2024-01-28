/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/28 22:45:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "error.h"
# include "../lib/libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define MAX_DIMENSION 1024
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
}				t_map;

typedef struct s_tiles
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}				t_tiles;

typedef struct s_game
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
}				t_game;

// Function pointer type declaration. 
typedef int	(*t_tile_function)(t_game *, int, int);

void	ft_error(void);
void	print_error(int err);
void	calculate_tile_size(t_game *game, int width, int height);
int		prepare_game_state(t_game *game);
int		load_map(t_game *game, char *map_file);
void	key_hook(mlx_key_data_t keydata, void *param);
void	render(t_game *game);
int		iterate_map(t_game *game, t_tile_function func);
int		validate_map(t_game *game);

#endif