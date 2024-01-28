/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/28 14:34:49 by lkilpela         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

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

int		load_map(t_game *game, char *map_file);
int		prepare_game_state(t_game *game);
void	ft_error(void);
void	key_hook(mlx_key_data_t keydata, void *param);
void	calculate_tile_size(t_game *game, int width, int height);
int		init_game_textures(t_game *game);
void	resize_game_tiles(t_game *game, int width, int height);
void	render(t_game *game);
int		iterate_map(t_game *game, t_tile_function func);
int		validate_map(t_game *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	print_error(int err);

#endif