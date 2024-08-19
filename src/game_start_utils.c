/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 13:11:01 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 14:01:45 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pos(t_map *map, char character, char coordinate)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->map_input[y][x] == character)
			{
				if (coordinate == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	count_collectibles(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->map_input[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	render_window(t_game *game)
{
	game->window = mlx_new_image(game->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	if (game->window == NULL)
	{
		print_msg("rendering window failed.");
		return (1);
	}
	if (mlx_image_to_window(game->mlx, game->window, 0, 0) < 0)
		return (1);
	return (0);
}
