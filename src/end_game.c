/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 10:36:45 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/17 11:34:52 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int end_game(t_game *game)
{
	printf("entering end_game function.\n");
    remove_textures(game);
	//remove_images(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	
	printf("exiting game_end function.\n");
    return 0;
}


// void load_pngs(t_game *game)
// {
// 	game->player->texture = mlx_load_png("./res/hero.png");
// 	if (game->player->texture == NULL)
// 	{
// 		printf("Failed to load texture from\n");
// 	}
// 	else
// 	{
// 		printf("Successfully loaded texture from\n");
// 		game->player->img = mlx_texture_to_image(game->mlx, game->player->texture);
// 		if (game->player->img == NULL)
// 		{
// 			printf("Failed to convert texture to image\n");
// 		}
// 		else
// 		{
// 			printf("Successfully converted texture to image\n");
// 		}
// 	}

// 	game->walls->texture = mlx_load_png("./res/wall.png");
// 	if (game->player->texture == NULL)
// 	{
// 		printf("Failed to load texture.\n");
// 	}
// 	else
// 	{
// 		printf("Successfully loaded texture.\n");
// 		game->walls->img = mlx_texture_to_image(game->mlx, game->walls->texture);
// 		if (game->walls->img == NULL)
// 		{
// 			printf("Failed to convert texture to image\n");
// 		}
// 		else
// 		{
// 			printf("Successfully converted texture to image\n");
// 		}
// 	}

// 	game->exit->texture = mlx_load_png("./res/exit.png");
// 	if (game->exit->texture == NULL)
// 	{
// 		printf("Failed to load texture.\n");
// 	}
// 	else
// 	{
// 		printf("Successfully loaded texture.\n");
// 		game->exit->img = mlx_texture_to_image(game->mlx, game->exit->texture);
// 		if (game->exit->img == NULL)
// 		{
// 			printf("Failed to convert texture to image\n");
// 		}
// 		else
// 		{
// 			printf("Successfully converted texture to image\n");
// 		}
// 	}

// 	game->background->texture = mlx_load_png("./res/background.png");
// 	if (game->background->texture == NULL)
// 	{
// 		printf("Failed to load texture.\n");
// 	}
// 	else
// 	{
// 		printf("Successfully loaded texture.\n");
// 		game->background->img = mlx_texture_to_image(game->mlx, game->background->texture);
// 		if (game->background->img == NULL)
// 		{
// 			printf("Failed to convert texture to image\n");
// 		}
// 		else
// 		{
// 			printf("Successfully converted texture to image\n");
// 		}
// 	}

// 	game->collectibles->texture = mlx_load_png("./res/collectible.png");
// 	if (game->collectibles->texture == NULL)
// 	{
// 		printf("Failed to load texture.\n");
// 	}
// 	else
// 	{
// 		printf("Successfully loaded texture.\n");
// 		game->collectibles->img = mlx_texture_to_image(game->mlx, game->collectibles->texture);
// 		if (game->collectibles->img == NULL)
// 		{
// 			printf("Failed to convert texture to image\n");
// 		}
// 		else
// 		{
// 			printf("Successfully converted texture to image\n");
// 		}
// 	}
	
// }