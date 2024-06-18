/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 13:27:11 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/18 18:12:41 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void populate_game_entities(t_game *game)
{
	game->player->x = get_pos(game, 'P', 'x');
	game->player->y = get_pos(game, 'P', 'y');
	game->exit->x = get_pos(game, 'E', 'x');
	game->exit->y = get_pos(game, 'E', 'y');
	game->num_collectibles = count_collectibles(game);
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
	while (i < game->map->rows)
	{
		int j = 0;
		while (j < game->map->cols)
		{
			pick_entity(game, i, j);
			j++;
		}
		i++;
	}  
}

int game_start(t_game *game)
{
	if (render_window(game) == 1)
	{
		print_error("rendering window failed.");
		return (1);
	}
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

int	load_pngs(t_game *game)
{
	game->player->texture = mlx_load_png("res/hero.png");
	if (game->player->texture == NULL)
		return (1);
	game->background->texture = mlx_load_png("res/background.png");
	if (game->background->texture == NULL)
		return (1);
	game->walls->texture = mlx_load_png("res/walls.png");
	if (game->walls->texture == NULL)
		return (1);
	game->exit->texture = mlx_load_png("res/exit.png");
	if (game->exit->texture == NULL)
		return (1);
	game->collectibles->texture = mlx_load_png("res/collectibles.png");
	if (game->collectibles->texture == NULL)
		return (1);
	return (0);
}



int	load_images(t_game *game)
{
	game->player->texture = mlx_texture_to_image(game->mlx, game->player);
	if (game->player->texture == NULL)
		return (1);
	game->background->texture = mlx_texture_to_image(game->mlx, game->background);
	if (game->background->texture == NULL)
		return (1);
	game->walls->texture = mlx_texture_to_image(game->mlx, game->walls);
	if (game->walls->texture == NULL)
		return (1);
	game->exit->texture = mlx_texture_to_image(game->mlx, game->exit);
	if (game->exit->texture == NULL)
		return (1);
	game->collectibles->texture = mlx_texture_to_image(game->mlx, game->collectibles);
	if (game->collectibles->texture == NULL)
		return (1);
	return (0);
}

