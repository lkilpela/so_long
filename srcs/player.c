/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:25:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/19 17:28:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void keyfunc(mlx_key_data_t keydata, void* param)
{
    
}

void init_player_movement(mlx_t* mlx, t_game *game)
{
    mlx_key_hook(mlx, keyfunc, game);
}