/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:43:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/17 11:12:47 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_game *game)
{
	printf("entering so_long function.\n");
	
	if (game_init(game) == 1)
	{
		printf("game_init failed\n");
		return 1;
	}
	
	if (game_start(game) == 1)
	{
		printf("game_start function failed\n");
		return (1);
	}
	
	
	// loop
	if (game_loop(game) == 1)
	{
		printf("game loop got fucked\n");
		return (1);
	}

	if (end_game(game) == 1)
	{
		printf("game end got fucked\n");
		return (1);
	}

	printf("exiting so_long function.\n");
	
	return (0);
}