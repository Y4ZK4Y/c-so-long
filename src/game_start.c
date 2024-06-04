/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/04 17:18:36 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"





// dont know where the render_window function should be
int render_window(t_game *game)
{
	game->window = mlx_new_image(game->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	if (game->window == NULL)
		return (1);
	mlx_image_to_window(game->mlx, game->window, 0 , 0);
	
	mlx_loop(game->mlx);
	return 0;
}



void draw_entity(t_game *game, t_entity *entity, int row, int col)
{
    int x = col * entity->width;
    int y = row * entity->height;

    mlx_image_to_window(game->mlx, entity->img, x, y);
}


int load_entity(t_game *game,t_entity *entity, const char *filepath)
{
	entity->texture = mlx_load_png(filepath);
	mlx_texture_to_image(game->mlx, entity->texture);
	if (entity->img == NULL)
	{
		printf("loading  failed\n");
		return (1);
	}
	return (0);
	
}




void render_static_elements(t_game *game)
{
    int i, j;
    for (i = 0; i < game->map->rows; i++)
    {
        for (j = 0; j < game->map->cols; j++)
        {
            char map_element = game->map->map_input[i][j];
            if (map_element == '1')
            {
				load_entity(game, game->walls, "./res/wall_cropped.png");
                draw_entity(game, game->walls, i, j);
            }
            else if (map_element == '0')
            {
				load_entity(game, game->background, "./res/background.png");
                draw_entity(game, game->background, i, j);
            }
            else if (map_element == 'E')
            {
				load_entity(game, game->exit, "./res/walls_cropped.c");
                draw_entity(game, game->entrance, i, j);
            }
            
        }
    }
}

int render_dynamic_elements(t_game *game)
{
    int i, j;
    for (i = 0; i < game->map->rows; i++)
    {
        for (j = 0; j < game->map->cols; j++)
        {
            char map_element = game->map->map_input[i][j];
            if (map_element == 'P')
            {
				if (load_entity(game, game->player, "./res/hero_cropped.png") == 1)
				{
					printf("load_entuity failed\n");
					return (1);
				}
				draw_entity(game, game->player, i, j);
				
            }
            else if (map_element == 'C')
            {
				if (load_entity(game, game->collectibles, "./res/enemy_cropped.png") == 1)
				{
					printf("load_entity failed\n");
					return (1);
				}
				draw_entity(game, game->collectibles, i, j);
		
            }
        }
    }
	return 0;
}






int game_start(t_game *game)
{
	
	if (render_window(game) == 1)
    {
        printf("render_window function failed\n");
        return (1);
    }

	render_static_elements(game);
	if (render_dynamic_elements(game) == 1)
		return 1;
	

	// event_listerner();
	return 0;
}