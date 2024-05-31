/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/31 16:49:40 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int render_window(t_game *game)
{
	void	*mlx_win;
	mlx_win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "GAME WINDOW");
    mlx_loop(game->mlx);
    return 0;
}


int game_start(t_game *game)
{
    
	if (render_window(game) == 1)
    {
        printf("render_window function failed\n");
        return (1);
    }
	// render_map();
	// render_entitties(); // including background, etc
	// event_listerner();
	return 0;
}