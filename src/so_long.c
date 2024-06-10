/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:43:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 14:04:33 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_game *game)
{
	// init
	if (game_init(game) == 1)
	{
		printf("game init failed\n");
		return 1;
	}
	
	
	// start
	if (game_start(game) == 1)
	{
		printf("game_start function failed\n");
		return (1);
	}
	// mlx_loop(game->mlx);
	// loop
	// if (game_loop(game) == 1)
	// {
	// 	printf("game loop got fucked\n");
	// 	return (1);
	// }

	// end
	// if (game_end(game) == 1)
	// {
	// 	printf("game end got fucked\n");
	// 	return (1);
	// }


	//remove_mlx_images(game);
	mlx_terminate(game->mlx);
	
	
	return (0);
}