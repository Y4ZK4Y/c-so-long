/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:44:58 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/07/26 11:44:43 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->player = NULL;
	game->collectibles = NULL;
	game->num_collectibles = 0;
	game->background = NULL;
	game->walls = NULL;
	game->exit = NULL;
	game->mlx = NULL;
	game->window = NULL;
}


void	init_map(t_map **map)
{
	(*map)->map_input = NULL;
	(*map)->rows = 0;
	(*map)->cols = 0;
	(*map)->c = 0;
	(*map)->foundE = 0;
}


void	init_entity(t_entity **entity)
{
	(*entity)->x = 0;
	(*entity)->y = 0;
	(*entity)->img = NULL;
	(*entity)->texture = NULL;
	(*entity)->xpm = NULL;				
}


int	init_mlx(t_game *game)
{
	game->mlx = mlx_init((game->map->cols * PIXEl_SIZE), (game->map->rows * PIXEl_SIZE), "GAME WINDOW", false);
	if (game->mlx == NULL)
	{
		print_msg("mlx init failed.");
		return (1);
	}
	return (0);
}



int	init(t_game *game)
{
	if (init_mlx(game) == 1)
		return (1);
	game->player = malloc(sizeof(t_entity));
	if (game->player == NULL)
		return (1);
	init_entity(&game->player);
	game->collectibles = malloc(sizeof(t_entity));
	if (game->collectibles == NULL)
		return (1);
	init_entity(&game->collectibles);
	game->background = malloc(sizeof(t_entity));
	if (game->background == NULL)
		return (1);
	init_entity(&game->background);
	game->walls = malloc(sizeof(t_entity));
	if (game->walls == NULL)
		return (1);
	init_entity(&game->walls);
	game->exit = malloc(sizeof(t_entity));
	if (game->exit == NULL)
		return (1);
	init_entity(&game->exit);
	return (0);
}
