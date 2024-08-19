/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 16:30:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 13:46:15 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(int num_moves)
{
	char	*move_str;

	move_str = NULL;
	move_str = ft_itoa(num_moves);
	write(STDOUT_FILENO, "Number of moves: ", 17);
	write(STDOUT_FILENO, move_str, ft_strlen(move_str));
	write(STDOUT_FILENO, "\n", 1);
	free(move_str);
}

void	move_right(t_game *game)
{
	char	*next_tile;

	next_tile = &game->map->map_input[game->player->y][game->player->x + 1];
	if (*next_tile == '1' || (*next_tile == 'E' && game->num_collectibles > 0))
		return ;
	else
	{
		if (*next_tile == 'C')
			game->num_collectibles--;
		else if (*next_tile == 'E' && game->num_collectibles == 0)
		{
			mlx_close_window(game->mlx);
			return ;
		}
		draw_entity(game, game->background, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = '0';
		game->player->x++;
		draw_entity(game, game->player, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = 'P';
		game->num_moves++;
		print_moves(game->num_moves);
	}
}

void	move_left(t_game *game)
{
	char	*previous_tile;

	previous_tile = &game->map->map_input[game->player->y][game->player->x - 1];
	if (*previous_tile == '1' || (*previous_tile == 'E' && \
	game->num_collectibles > 0))
		return ;
	else
	{
		if (*previous_tile == 'C')
			game->num_collectibles--;
		else if (*previous_tile == 'E' && game->num_collectibles == 0)
		{
			mlx_close_window(game->mlx);
			return ;
		}
		draw_entity(game, game->background, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = '0';
		game->player->x--;
		draw_entity(game, game->player, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = 'P';
		game->num_moves++;
		print_moves(game->num_moves);
	}
}

void	move_up(t_game *game)
{
	char	*up_tile;

	up_tile = &game->map->map_input[game->player->y - 1][game->player->x];
	if (*up_tile == '1' || (*up_tile == 'X' && game->num_collectibles > 0))
		return ;
	else
	{
		if (*up_tile == 'C')
			game->num_collectibles--;
		else if (*up_tile == 'E' && game->num_collectibles == 0)
		{
			mlx_close_window(game->mlx);
			return ;
		}
		draw_entity(game, game->background, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = '0';
		game->player->y--;
		draw_entity(game, game->player, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = 'P';
		game->num_moves++;
		print_moves(game->num_moves);
	}
}

void	move_down(t_game *game)
{
	char	*down_tile;

	down_tile = &game->map->map_input[game->player->y + 1][game->player->x];
	if (*down_tile == '1' || (*down_tile == 'E' && game->num_collectibles > 0))
		return ;
	else
	{
		if (*down_tile == 'C')
			game->num_collectibles--;
		else if (*down_tile == 'E' && game->num_collectibles == 0)
		{
			mlx_close_window(game->mlx);
			return ;
		}
		draw_entity(game, game->background, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = '0';
		game->player->y++;
		draw_entity(game, game->player, game->player->y, game->player->x);
		game->map->map_input[game->player->y][game->player->x] = 'P';
		game->num_moves++;
		print_moves(game->num_moves);
	}
}
