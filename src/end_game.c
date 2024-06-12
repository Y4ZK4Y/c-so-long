/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 10:36:45 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/12 13:21:32 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int end_game(t_game *game)
{
    remove_textures(game);
	remove_images(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
    return 0;
}