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






void    draw_entity(t_game *game, t_entity *entity, int row, int col)
{
    // int x = col * ENTITY_WIDTH;
    // int y = row * ENTITY_HEIGHT;
    

    mlx_image_to_window(game->mlx, entity->img, 10, 10);
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
				load_entity(game, game->walls, "./res/wall.png");
                draw_entity(game, game->walls, i, j);
            }
            else if (map_element == '0')
            {
				load_entity(game, game->background, "./res/background.png");
                draw_entity(game, game->background, i, j);
            }
            else if (map_element == 'E')
            {
				load_entity(game, game->exit, "./res/exit.png");
                draw_entity(game, game->exit, i, j);
            }
            else if (map_element == 'P')
            {
				load_entity(game, game->player, "./res/hero.png");
                draw_entity(game, game->player, i, j);
            }
            else if (map_element == 'C')
            {
				load_entity(game, game->collectibles, "./res/collectible.png");
                draw_entity(game, game->collectibles, i, j);
            }
            j++;
        }
        i++;
    }
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

void populate_game_entities(t_game *game)
{
    game->player->x = get_pos(game, 'P', 'x');
    game->player->y = get_pos(game, 'P', 'y');
    game->exit->x = get_pos(game, 'E', 'x');
    game->exit->y = get_pos(game, 'E', 'y');
    //printf("num of c: %d\n", count_collectibles(game));

//     printf("Player position: (%d, %d)\n", game->player->x, game->player->y);
//     printf("Exit position: (%d, %d)\n", game->exit->x, game->exit->y);
//     printf("Number of collectibles: %d\n", game->num_collectibles);

}
int load_entity(t_game *game,t_entity *entity, const char *filepath)
{
    if (entity == NULL)
    {
        printf("entity is NULL");
        return 1;
    }
	if ((entity->texture = mlx_load_png(filepath)) == NULL)
        printf("mlx load png failed\n");
	if ((entity->img = mlx_texture_to_image(game->mlx, entity->texture)) == NULL)
        printf("mlx txture to image failed\n");
	if (entity->img == NULL)
	{
		printf("loading  failed\n");
		return (1);
	}
    mlx_delete_texture(entity->texture);
	return (0);
	
}


void load_pngs(t_game *game)
{
    char *png_files[] = {
        "./res/wall.png",
        "./res/hero.png",
        "./res/exit.png",
        "./res/background.png",
        "./res/collectible.png"
    };
    t_entity *entities[] = {
        game->walls,
        game->player,
        game->exit,
        game->background,
        game->collectibles
    };
    int num_png_files = sizeof(png_files) / sizeof(png_files[0]);

    for (int i = 0; i < num_png_files; i++)
    {
        load_entity(game, entities[i], png_files[i]);
    }
}

int game_start(t_game *game)
{
    // printf("Game state:\n");

    // printf("Player: x = %d, y = %d\n", game->player->x, game->player->y);
    // printf("Exit: x = %d, y = %d\n", game->exit->x, game->exit->y);

    // printf("Map: rows = %d, cols = %d\n", game->map->rows, game->map->cols);
    // for (int i = 0; i < game->map->rows; i++)
    // {
    //     for (int j = 0; j < game->map->cols; j++)
    //     {
    //         printf("%c ", game->map->map_input[i][j]);
    //     }
    //     printf("\n");
    // }

    load_pngs(game);
    populate_game_entities(game);


//  printf("Game state after calling populate:\n");

//     printf("Player: x = %d, y = %d\n", game->player->x, game->player->y);
//     printf("Exit: x = %d, y = %d\n", game->exit->x, game->exit->y);

//     printf("Map: rows = %d, cols = %d\n", game->map->rows, game->map->cols);
//     for (int i = 0; i < game->map->rows; i++)
//     {
//         for (int j = 0; j < game->map->cols; j++)
//         {
//             printf("%c ", game->map->map_input[i][j]);
//         }
//         printf("\n");
//     }
    render_elements(game);
	// event_listener();
    return (0);
	
}




