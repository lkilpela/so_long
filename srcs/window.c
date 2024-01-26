/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:41 by lkilpela          #+#    #+#             */
/*   Updated: 2024/01/26 13:54:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize_window(int width, int height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx_ptr, game->tiles.collectible);
	mlx_delete_image(game->mlx_ptr, game->tiles.exit);
	mlx_delete_image(game->mlx_ptr, game->tiles.player);
	mlx_delete_image(game->mlx_ptr, game->tiles.wall);
	mlx_delete_image(game->mlx_ptr, game->tiles.floor);
	init_game_textures(game);
	resize_game_tiles(game, width, height);
	render(game);
}
