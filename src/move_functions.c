/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 16:30:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/18 11:57:46 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void move_right(t_game *game)
{
    char *next_tile;
    next_tile = &game->map->map_input[game->player->y][game->player->x+1];
    
    printf("Current tile: %c\n", game->map->map_input[game->player->y][game->player->x]);
    printf("Next tile: %c\n", *next_tile);
    
    if (*next_tile == '1')
    {
        return;
    }
    else
    {
        if (*next_tile == 'C')
        {
            game->num_collectibles--;
        }
        else if (*next_tile == 'X' && game->num_collectibles == 0)
        {
            mlx_close_window(game->mlx);
            return;
        }
        draw_entity(game, game->background, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = '0';
        game->player->x++;
        draw_entity(game, game->player, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = 'P';
    }
    printf("num of collectibles: %d\n", game->num_collectibles);
    printf("player position at (%d, %d)\n", game->player->x, game->player->y);

}

void move_left(t_game *game)
{
    char *previous_tile;
    previous_tile = &game->map->map_input[game->player->y][game->player->x-1];
    
    printf("Current tile: %c\n", game->map->map_input[game->player->y][game->player->x]);
    printf("Previous tile: %c\n", *previous_tile);

    if (*previous_tile == '1')
    {
        return;
    }
    else
    {
        if (*previous_tile == 'C')
            game->num_collectibles--;
        else if (*previous_tile == 'X' && game->num_collectibles == 0)
        {
            mlx_close_window(game->mlx);
            return;
        }
        draw_entity(game, game->background, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = '0';
        game->player->x--;
        draw_entity(game, game->player, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = 'P';
    }
    printf("num of collectibles: %d\n", game->num_collectibles);
    printf("player position at (%d, %d)\n", game->player->x, game->player->y);

}

void move_up(t_game *game)
{
    char *up_tile;
    up_tile = &game->map->map_input[game->player->y-1][game->player->x];
    
    printf("Current tile: %c\n", game->map->map_input[game->player->y][game->player->x]);
    printf("Next tile: %c\n", *up_tile);
    
    if (*up_tile == '1')
    {
        return;
    }
    else
    {
        if (*up_tile == 'C')
        {
            game->num_collectibles--;
        }
        else if (*up_tile == 'X' && game->num_collectibles == 0)
        {
            mlx_close_window(game->mlx);
            return;
        }
        draw_entity(game, game->background, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = '0';
        game->player->y--;
        draw_entity(game, game->player, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = 'P';
    }
    printf("num of collectibles: %d\n", game->num_collectibles);
    printf("player position at (%d, %d)\n", game->player->x, game->player->y);
}


void move_down(t_game *game)
{
    char *down_tile;
    down_tile = &game->map->map_input[game->player->y+1][game->player->x];
    
    printf("Current tile: %c\n", game->map->map_input[game->player->y][game->player->x]);
    printf("Next tile: %c\n", *down_tile);
    
    if (*down_tile == '1')
    {
        return;
    }
    else
    {
        if (*down_tile == 'C')
        {
            game->num_collectibles--;
        }
        else if (*down_tile == 'X' && game->num_collectibles == 0)
        {
            mlx_close_window(game->mlx);
            return;
        }
        draw_entity(game, game->background, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = '0';
        game->player->y++;
        draw_entity(game, game->player, game->player->y, game->player->x);
        game->map->map_input[game->player->y][game->player->x] = 'P';
    }
    printf("num of collectibles: %d\n", game->num_collectibles);
    printf("player position at (%d, %d)\n", game->player->x, game->player->y);

}