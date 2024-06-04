// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   render_things.c                                    :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/06/04 16:15:40 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/04 16:44:54 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"


// // put things in their right spot




// void draw_entity(t_game *game, t_entity *entity, int row, int col)
// {
//     int x = col * entity->width;
//     int y = row * entity->height;

//     mlx_image_to_window(game->mlx, entity->img, x, y);
// }




//  if (type == PLAYER)
//     {
//         // Draw player
//     }
//     else if (type == ENEMY)
//     {
//         // Draw enemy
//     }
//     else if (type == COLLECTIBLE)
//     {
//         // Draw collectible
//     }
//     else if (type == WALL)
//     {
//         // Draw wall
//     }
//     else if (type == ENTRANCE)
//     {
//         // Draw entrance
//     }
//     else if (type == EXIT)
//     {
//         // Draw exit
//     }



	

// void render_static_elements(t_game *game)
// {
//     int i, j;
//     for (i = 0; i < game->map->rows; i++)
//     {
//         for (j = 0; j < game->map->cols; j++)
//         {
//             char map_element = game->map->map_input[i][j];
//             if (map_element == '1')
//             {
//                 draw_entity(game, game->walls, i, j);
//             }
//             else if (map_element == '0')
//             {
//                 draw_entity(game, game->background, i, j);
//             }
//             else if (map_element == 'E')
//             {
//                 draw_entity(game, game->entrance, i, j);
//             }
//             else if (map_element == 'X')
//             {
//                 draw_entity(game, game->exit, i, j);
//             }
//         }
//     }
// }

// void render_dynamic_elements(t_game *game)
// {
//     int i, j;
//     for (i = 0; i < game->map->rows; i++)
//     {
//         for (j = 0; j < game->map->cols; j++)
//         {
//             char map_element = game->map->map_input[i][j];
//             if (map_element == 'P')
//             {
//                 draw_entity(game, game->player, i, j);
//             }
//             else if (map_element == 'C')
//             {
//                 draw_entity(game, game->collectibles, i, j);
//             }
//         }
//     }
// }


