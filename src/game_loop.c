/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 16:34:00 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 14:02:03 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// dont know where the render_window function should be
int render_window(t_game *game)
{
	game->window = mlx_new_image(game->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	if (game->window == NULL)
		return (1);
	//mlx_image_to_window(game->mlx, game->window,  0, 0);
	
	return 0;
}