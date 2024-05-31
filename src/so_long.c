/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:43:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/31 16:19:28 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_game *game)
{
	if (game_init(game) == 1)
		printf("game init failed\n");
	if (game_start(game) == 1)
	{
		printf("game_start function failed\n");
		return (1);
	}
	


	return (0);
}