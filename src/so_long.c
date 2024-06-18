/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:43:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/18 18:12:21 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    key_input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (game->num_collectibles == 0 && game->map->map_input[game->player->y][game->player->x] == 'X')
    {
        //mlx_loop_end(game->mlx);
        mlx_close_window(game->mlx);
    }
    else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
    {
        printf("up\n");
        move_up(game);
    }
    else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
    {
        printf("down\n");
        move_down(game);
    }
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
    {
        printf("right\n");
        move_right(game);
    }
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
    {
        printf("left\n");
        move_left(game);
    }
    
}



int	so_long(t_game *game)
{
	if (init(game) == 1)
		return (1);
	// if (game_start(game) == 1)
	// 	return (1);
	if (render_window(game) == 1)
		return (1);
    if (load_pngs(game) == 1)
        return ((print_error("loading png failed.")), 1);
    if (load_images(game) == 1)
        return ((print_error("loading images failed.")), 1);
    delete_textures(game);
    populate_game_entities(game);
    
	mlx_key_hook(game->mlx, &key_input, game);

    //mlx_loop_hook();
    mlx_loop(game->mlx);
    
    remove_images(game);
	
	return (0);
}
