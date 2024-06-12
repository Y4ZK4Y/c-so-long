/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 16:34:00 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/12 13:21:19 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// dont know where the render_window function should be
int game_loop(t_game *game)
{
    mlx_loop(game->mlx);
	
	return 0;
}