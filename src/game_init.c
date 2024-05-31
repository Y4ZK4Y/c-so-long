/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:44:58 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/31 16:18:50 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// init_img()
// {
// 	mlx_image_t	*img;
	
// }

// init_data()
// {
// 	// init everything
	
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
	return (0);				
}






int	init_mlx(t_game *game)
{
	//void	*mlx_win;
	if (game == NULL)
    {
        printf("game pointer is NULL, msg from init_mlx\n");
        return (1);
    }
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "GAME WINDOW", false);
	if (game->mlx == NULL)
	{
		printf("mlx init failed from the inside\n");
		return (1);
	}
	//mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	return (0);
}



int	game_init(t_game *game)
{
	 if (game == NULL)
    {
        printf("game pointer is NULL, msg from game_init\n");
        return (1);
    }
	if (init_mlx(game) == 1)
		printf("init mlx failed\n");
	

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
	if (init_entity(&game->entrance) == 1)
		{
		printf("entrance init failed\n");
		return (1);
	}
	if (init_entity(&game->exit) == 1)
		{
		printf("exit init failed\n");
		return (1);
	}
	//init_image();
	
	//init_data(); // init anything that's left
	
	// init_img();
	return (0);
	
}

