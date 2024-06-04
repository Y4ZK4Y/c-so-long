// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   load_assets.c                                      :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/06/04 12:36:43 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/04 17:02:42 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"


// int	load_walls(t_game *game)
// {
	
// 	game->walls->texture = mlx_load_png("./res/wall_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->walls->texture);
// 	if (game->walls->img == NULL)
// 	{
// 		printf("loading walls failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->walls->img, 0, 0);
// 	return (0);
	
// }


// int	load_background(t_game *game)
// {
	
// 	game->background->texture = mlx_load_png("./res/background.png");
// 	mlx_texture_to_image(game->mlx, game->background->texture);
// 	if (!game->background->img)
// 	{
// 		printf("loading background failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->background->img, 0, 0);
// 	return (0);
	
// }

// int	load_entrance(t_game *game)
// {
	
// 	game->entrance->texture = mlx_load_png("./res/walls_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->entrance->texture);
// 	if (game->entrance->img == NULL)
// 	{
// 		printf("loading entrance failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->entrance->img, 100, 100);
// 	return (0);
	
// }

// int	load_exit(t_game *game)
// {
	
// 	game->exit->texture = mlx_load_png("./res/walls_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->exit->texture);
// 	if (game->exit->img == NULL)
// 	{
// 		printf("loading exit failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->exit->img, 0, 0);
// 	return (0);
	
// }


// int	load_collectibles(t_game *game)
// {
	
// 	game->collectibles->texture = mlx_load_png("./res/enemy_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->collectibles->texture);
// 	if (game->collectibles->img == NULL)
// 	{
// 		printf("loading collectibles failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->collectibles->img, 0, 0);
// 	return (0);
	
// }


