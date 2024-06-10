/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 15:53:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 14:22:49 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void init_main_struct(t_game *game)
{
    if (game != NULL)
    {
        game->player = NULL;
        game->collectibles = NULL;
        game->background = NULL;
        game->walls = NULL;
        game->exit = NULL;
        game->map = NULL;
        game->window = NULL;
		game->num_collectibles = 0;
        //game->mlx = NULL;
    }
}


int main(int argc, char **argv)
{
	t_game	game;

	init_main_struct(&game);
	if (argc != 2)
	{
		free_game(&game);
		display_error_exit("few arguments provided.", EXIT_FAILURE);
	}
	
	if (parse_input(&game, argv[1]) == 1)
	{
		free_game(&game);
		display_error_exit("parsing failed.", EXIT_FAILURE);
	}
	
	//has leakes
	if (so_long(&game) == 1)
	{
		free_game(&game);
		display_error_exit("so_long failed", EXIT_FAILURE);
	}

	free_game(&game);

	return (0);
}
