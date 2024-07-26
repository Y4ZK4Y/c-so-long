/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 15:53:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/07/26 16:48:28 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		display_error_exit("few arguments provided.", EXIT_FAILURE);
	init_game_struct(&game);
	parse_input(&game, argv[1]);
	if (so_long(&game) == 1)
		free_game(&game, "so_long function failed.", EXIT_FAILURE, NULL);
	free_game(&game, NULL, EXIT_SUCCESS, NULL);
	mlx_terminate(game.mlx);
	return (0);
}
