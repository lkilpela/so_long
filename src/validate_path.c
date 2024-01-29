/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/29 11:40:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_direction(t_game *game)
{
	int move_x[4];
	int move_y[4];
	
	move_x[0] = -1;// Move up
    move_x[1] = 1;// Move down
    move_x[2] = 0;// No vertical movement
    move_x[3] = 0;// No vertical movement
	move_y[0] = 0;   // No horizontal movement
    move_y[1] = 0;   // No horizontal movement
    move_y[2] = -1;  // Move left
    move_y[3] = 1;   // Move right
}

int validate_path(t_game *game)
