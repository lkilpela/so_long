/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:39:15 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/11 21:59:59 by lkilpela         ###   ########.fr       */
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

typedef struct	s_game 
{
	int		fox_x;
	int		fox_y;
	int		*apple_x;
	int		*apple_y;
	int		apple_count;
	int		*tree_x;
	int		*tree_y;
	int		tree_count;
	int		door_x;
	int		door_y;
	char	**map;
	int		map_width;
	int		map_height;
}				t_game;