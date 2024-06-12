/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 13:11:01 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/12 14:18:28 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


size_t get_pos(t_game *game, char character, char coordinate)
{
    size_t x, y;
    y = 0;
    while (y < game->map->rows)
    {
        x = 0;
        while (x < game->map->cols)
        {
            if (game->map->map_input[y][x] == character)
            {
                if (coordinate == 'x')
                    return x;
                else
                    return y;
            }
            x++;
        }
        y++;
    }
    return 0;

}


int count_collectibles(t_game *game)
{
    size_t x, y;
    int count = 0;

    y = 0;
    //x = 0;
    while ( y < game->map->rows)
    {
         x = 0;
        while (x < game->map->cols)
        {
            if (game->map->map_input[y][x] == 'C')
            {
                count++;
            }
            x++;
        }
        y++;
    }
    return count;
}



int render_window(t_game *game)
{
	game->window = mlx_new_image(game->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	if (game->window == NULL)
		return (1);
	mlx_image_to_window(game->mlx, game->window,  0, 0);
	
	return 0;
}

