/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/11 15:30:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAX_MAP_WIDTH 256
# define MAX_MAP_HEIGHT 256

# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

typedef struct	s_map
{
    char	**map;
    int		width;
    int		height;
}				t_map;

#endif