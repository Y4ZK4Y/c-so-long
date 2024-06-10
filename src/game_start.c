// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   game_start.c                                       :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/10 12:20:47 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"



int get_pos(t_game *game, char character, char coordinate)
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
    return -1;

}

int count_collectibles(t_game *game)
{
    size_t x, y;
    int count = 0;

    y = 0;
    x = 0;
    while ( y < game->map->rows)
    {
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


void populate_game_entities(t_game *game)
{
    game->player->x = get_pos(game, 'P', 'x');
    game->player->y = get_pos(game, 'P', 'y');
    game->exit->x = get_pos(game, 'X', 'x');
    game->exit->y = get_pos(game, 'X', 'y');
    count_collectibles(game);
}


int load_entity(t_game *game,t_entity *entity, const char *filepath)
{
    if (entity == NULL)
    {
        printf("entity is NULL");
        return 1;
    }
	entity->texture = mlx_load_png(filepath);
	entity->img = mlx_texture_to_image(game->mlx, entity->texture);
	if (entity->img == NULL)
	{
		printf("loading  failed\n");
		return (1);
	}
    mlx_delete_texture(entity->texture);
	return (0);
	
}




void    draw_entity(t_game *game, t_entity *entity, int row, int col)
{
    int x = col * ENTITY_WIDTH;
    int y = row * ENTITY_HEIGHT;

    mlx_image_to_window(game->mlx, entity->img, x, y);
}




void render_elements(t_game *game)
{
    int i, j;
    char map_element;
    map_element = '\0';
    i = 0;
    while (i < game->map->rows)
    {
        j = 0;
        while (j < game->map->cols)
        {
            map_element = game->map->map_input[i][j];
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
                draw_entity(game, game->exit, i, j);
            }
            else if (map_element == 'P')
            {
				load_entity(game, game->player, "./res/walls_cropped.c");
                draw_entity(game, game->player, i, j);
            }
            else if (map_element == 'C')
            {
				load_entity(game, game->collectibles, "./res/walls_cropped.c");
                draw_entity(game, game->collectibles, i, j);
            }
            j++;
        }
        i++;
    }
}





int game_start(t_game *game)
{
    populate_game_entities(game);


    render_elements(game);

	
	// event_listener();
    return (0);
	
}