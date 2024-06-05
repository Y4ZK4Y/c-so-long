/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 16:30:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/05 14:41:56 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.c"


// //  move r l u d

// int move_up(t_game *game)
// {
    
// }

// int move_down(t_game *game)
// {
    
// }

// int move_left(t_game *game)
// {
    
// }

// int move_right(t_game *game)
// {
    
// }

// int move_up(t_game *game)
// {
//     if (game->player.y > 0 && game->map[game->player.y - 1][game->player.x] != WALL)
//     {
//         game->player.y--;
//         draw_entity(game, PLAYER, game->player.y, game->player.x);
//         return SUCCESS;
//     }
//     return ERROR_GAME_LOOP;
// }

// int move_down(t_game *game)
// {
//     if (game->player.y < game->map_height - 1 && game->map[game->player.y + 1][game->player.x] != WALL)
//     {
//         game->player.y++;
//         draw_entity(game, PLAYER, game->player.y, game->player.x);
//         return SUCCESS;
//     }
//     return ERROR_GAME_LOOP;
// }

// int move_left(t_game *game)
// {
//     if (game->player.x > 0 && game->map[game->player.y][game->player.x - 1] != WALL)
//     {
//         game->player.x--;
//         draw_entity(game, PLAYER, game->player.y, game->player.x);
//         return SUCCESS;
//     }
//     return ERROR_GAME_LOOP;
// }

// int move_right(t_game *game)
// {
//     if (game->player.x < game->map_width - 1 && game->map[game->player.y][game->player.x + 1] != WALL)
//     {
//         game->player.x++;
//         draw_entity(game, PLAYER, game->player.y, game->player.x);
//         return SUCCESS;
//     }
//     return ERROR_GAME_LOOP;
// }