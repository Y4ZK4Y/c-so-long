/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/17 11:34:56 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void populate_game_entities(t_game *game)
{
    game->player->x = get_pos(game, 'P', 'x');
    //printf("Player x position: %d\n", game->player->x);

    game->player->y = get_pos(game, 'P', 'y');
    //printf("Player y position: %d\n", game->player->y);

    game->exit->x = get_pos(game, 'E', 'x');
    //printf("Exit x position: %d\n", game->exit->x);

    game->exit->y = get_pos(game, 'E', 'y');
    //printf("Exit y position: %d\n", game->exit->y);

    game->num_collectibles = count_collectibles(game);
    //printf("Number of collectibles: %d\n", game->num_collectibles);

}



void    draw_entity(t_game *game, t_entity *entity, int y, int x)
{
    if (entity == NULL)
        {
            printf("Error: Attempted to draw a NULL entity\n");
            return;
        }
        if (entity->img == NULL)
        {
            printf("Error: Entity has no image to draw\n");
            return;
        }
        
    int pixel_x = x * PIXEl_SIZE;
    int pixel_y = y * PIXEl_SIZE;

    mlx_image_to_window(game->mlx, entity->img, pixel_x, pixel_y);
    printf("Entity drawn at (%d, %d)\n", x, y);
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
    t_entity **entities[] = {
        &game->walls,
        &game->player,
        &game->exit,
        &game->background,
        &game->collectibles
    };
    int num_png_files = sizeof(png_files) / sizeof(png_files[0]);

    for (int i = 0; i < num_png_files; i++)
    {
        (*entities[i])->texture = mlx_load_png(png_files[i]);
        if ((*entities[i])->texture == NULL)
        {
            printf("Failed to load texture from %s\n", png_files[i]);
          
        }
        else
        {
            printf("Successfully loaded texture from %s\n", png_files[i]);
            (*entities[i])->img = mlx_texture_to_image(game->mlx, (*entities[i])->texture);
            if ((*entities[i])->img == NULL)
            {
                printf("Failed to convert texture to image for %s\n", png_files[i]);
            }
            else
            {
                printf("Successfully converted texture to image for %s\n", png_files[i]);
            }
        }
    }
}


void pick_entity(t_game *game, int i, int j)
{
    draw_entity(game, game->exit, game->exit->y, game->exit->x);
    if (game->map->map_input[i][j] == '0')
    {
        draw_entity(game, game->background, i, j);
    }
    if (game->map->map_input[i][j] == '1')
    {
        draw_entity(game, game->walls, i, j);
    }
    if (game->map->map_input[i][j] == 'C')
    {
        draw_entity(game, game->collectibles, i, j);
    }
    if (game->map->map_input[i][j] == 'P')
    {
        draw_entity(game, game->player, game->player->y, game->player->x);
    }
}



void render_game(t_game *game)
{
    int i = 0;
    while (i < game->map->rows) // iterate over rows
    {
        int j = 0;
        while (j < game->map->cols) // iterate over columns in each row
        {
            pick_entity(game, i, j);
            j++;
        }
        i++;
    }  
}

int game_start(t_game *game)
{
    printf("entering start_game function.\n");

    if (render_window(game) == 1)
    {
        printf("render_window function failed\n");
        return (1);
    }
    printf("render_window function successful.\n");

    load_pngs(game);
    printf("load_pngs function executed.\n");

    populate_game_entities(game);
    printf("populate_game_entities function executed.\n");

    render_game(game);
    
    printf("render_game function executed.\n");

    // if (event_listener() == 1)
    // {
    //     printf("event listener function got fucked.\n");
    //     return 1;
    // }
    printf("event_listener function executed.\n");
    printf("exiting start_game function.\n");

    return (0);
}

