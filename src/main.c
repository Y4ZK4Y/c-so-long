/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 15:53:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/05 16:36:46 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
    {
        printf("Failed to allocate memory for game(inside main)\n");
        return (1);
    }
	
	if (argc != 2)
		display_error_exit("few arguments provided.", EXIT_FAILURE);
	
	if (parse_input(game, argv[1]) == 1)
		display_error_exit("parsing failed.", EXIT_FAILURE);
	
	
	if (so_long(game) == 1)
		display_error_exit("so_long failed", EXIT_FAILURE);

	free_game(game);

	return (0);
}
