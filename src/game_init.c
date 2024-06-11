/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:44:58 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/11 19:25:53 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// init_data()
// {
// 	// init everything that's left
	
// }


void	init_map(t_map *map)
{
	map->map_input = NULL;
	map->rows = 0;
	map->cols = 0;
}




void init_game_struct(t_game *game)
{
	game->player = NULL;
	game->collectibles = NULL;
	game->num_collectibles = 0;
	game->background = NULL;
	game->walls = NULL;
	game->exit = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->window = NULL;
}


int	init_entity(t_entity **entity)
{
	*entity = malloc(sizeof(t_entity));
	if (*entity == NULL)
		return (1);
	(*entity)->x = 0;
	(*entity)->y = 0;
	(*entity)->img = NULL;
	(*entity)->texture = NULL;
	return (0);				
}


int	init_mlx(t_game **game)
{
	(*game)->mlx = mlx_init(700, 700, "GAME WINDOW", false);
	if ((*game)->mlx == NULL)
	{
		printf("mlx init failed from the inside\n");
		return (1);
	}
	return (0);
}




int	game_init(t_game *game)
{
	if (init_mlx(&game) == 1)
	{
		printf("init mlx failed\n");
		return 1;
	}
	if (init_entity(&game->player) == 1)
	{
		printf("player init failed\n");
		return (1);
	}
	if (init_entity(&game->collectibles) == 1)
	{
		printf("collectible init failed\n");
		return (1);
	}
	if (init_entity(&game->background) == 1)
	{
		printf("background init failed\n");
		return (1);
	}
	if (init_entity(&game->walls) == 1)
	{
		printf("walls init failed\n");
		return (1);
	}
	
	if (init_entity(&game->exit) == 1)
	{
		printf("exit init failed\n");
		return (1);
	}
	//init_data(); // init anything that's left
	return (0);
}
