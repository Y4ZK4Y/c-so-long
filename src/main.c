/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 15:53:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/12 13:46:31 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	t_game	game;

	init_game_struct(&game);
	if (argc != 2)
		display_error_exit("few arguments provided.", EXIT_FAILURE);
	if (parse_input(&game, argv[1]) == 1)
		free_game(&game, "parsing failed.", EXIT_FAILURE);
	if (so_long(&game) == 1)
		free_game(&game, "so_long failed", EXIT_FAILURE);
	free_game(&game, "went well\n", EXIT_SUCCESS);
	return (0);
}
