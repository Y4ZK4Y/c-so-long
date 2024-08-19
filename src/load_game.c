/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 13:59:54 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	populate_game_entities(t_game *game)
{
	game->player->x = get_pos(game->map, 'P', 'x');
	game->player->y = get_pos(game->map, 'P', 'y');
	game->exit->x = get_pos(game->map, 'E', 'x');
	game->exit->y = get_pos(game->map, 'E', 'y');
	game->num_collectibles = count_collectibles(game->map);
}

int	draw_entity(t_game *game, t_entity *entity, int y, int x)
{
	int	pixel_x;
	int	pixel_y;

	if (entity == NULL)
	{
		print_msg("Attempted to draw a NULL entity.");
		return (1);
	}
	if (entity->img == NULL)
	{
		print_msg("Entity has no image to draw.");
		return (1);
	}
	pixel_x = x * PIXEL_SIZE;
	pixel_y = y * PIXEL_SIZE;
	if (mlx_image_to_window(game->mlx, entity->img, pixel_x, pixel_y) <  0)
		return (1);
	return (0);
}

int	pick_entity(t_game *game, int i, int j)
{
	if (draw_entity(game, game->exit, game->exit->y, game->exit->x) == 1)
		return (1);
	if (game->map->map_input[i][j] == '0')
		if (draw_entity(game, game->background, i, j) == 1)
			return (1);
	if (game->map->map_input[i][j] == '1')
		if (draw_entity(game, game->walls, i, j) == 1)
			return (1);
	if (game->map->map_input[i][j] == 'C')
		if (draw_entity(game, game->collectibles, i, j) == 1)
			return (1);
	if (game->map->map_input[i][j] == 'P')
		if (draw_entity(game, game->player, game->player->y, game->player->x) == 1)
			return (1);
	return (0);
}

int	load_pngs(t_game *game)
{
	game->player->texture = mlx_load_png("textures/hero.png");
	if (game->player->texture == NULL)
		return (1);
	game->background->texture = mlx_load_png("textures/background.png");
	if (game->background->texture == NULL)
		return (1);
	game->walls->texture = mlx_load_png("textures/wall.png");
	if (game->walls->texture == NULL)
		return (1);
	game->exit->texture = mlx_load_png("textures/exit.png");
	if (game->exit->texture == NULL)
		return (1);
	game->collectibles->texture = mlx_load_png("textures/collectible.png");
	if (game->collectibles->texture == NULL)
		return (1);
	return (0);
}

int	load_images(t_game *game)
{
	game->player->img = mlx_texture_to_image(game->mlx, game->player->texture);
	if (game->player->img == NULL)
		return (1);
	game->background->img = mlx_texture_to_image(game->mlx, \
	game->background->texture);
	if (game->background->img == NULL)
		return (1);
	game->walls->img = mlx_texture_to_image(game->mlx, game->walls->texture);
	if (game->walls->img == NULL)
		return (1);
	game->exit->img = mlx_texture_to_image(game->mlx, game->exit->texture);
	if (game->exit->img == NULL)
		return (1);
	game->collectibles->img = mlx_texture_to_image(game->mlx, \
	game->collectibles->texture);
	if (game->collectibles->img == NULL)
		return (1);
	return (0);
}
