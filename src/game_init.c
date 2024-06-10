/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:44:58 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 15:11:30 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// init_data()
// {
// 	// init everything that's left
	
// }



int	init_entity(t_entity **entity)
{
	*entity = malloc(sizeof(t_entity));
	if (*entity == NULL)
		return (1);
	(*entity)->x = 0;
	(*entity)->y = 0;
	(*entity)->width= 0;
	(*entity)->height = 0;
	(*entity)->type = 0;
	(*entity)->img = NULL;
	(*entity)->texture = NULL;
	return (0);				
}


int	init_mlx(t_game *game)
{
	if (game == NULL)
    {
        printf("game pointer is NULL, msg from init_mlx\n");
        return (1);
    }
	game->mlx = mlx_init(WINDOW_WIDTH , WINDOW_HEIGHT, "GAME WINDOW", false);
	if (game->mlx == NULL)
	{
		printf("mlx init failed from the inside\n");
		return (1);
	}
	return (0);
}




int	game_init(t_game *game)
{
	if (init_mlx(game) == 1)
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
