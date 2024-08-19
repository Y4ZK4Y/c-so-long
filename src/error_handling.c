/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:35:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 11:30:27 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_msg(const char *errmsg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	write(STDERR_FILENO, "\n", 1);
}

void	remove_textures(t_game *game)
{
	mlx_delete_texture(game->player->texture);
	mlx_delete_texture(game->collectibles->texture);
	mlx_delete_texture(game->background->texture);
	mlx_delete_texture(game->walls->texture);
	mlx_delete_texture(game->exit->texture);
}

void	remove_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->player->img);
	mlx_delete_image(game->mlx, game->walls->img);
	mlx_delete_image(game->mlx, game->background->img);
	mlx_delete_image(game->mlx, game->collectibles->img);
	mlx_delete_image(game->mlx, game->exit->img);
}

void	free_game(t_game *game, const char *errmsg, int exit_code, char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	if (game->map != NULL)
		free_map(game->map);
	if (game->player != NULL)
		free_entity(&game->player);
	if (game->collectibles != NULL)
		free_entity(&game->collectibles);
	if (game->background != NULL)
		free_entity(&game->background);
	if (game->walls != NULL)
		free_entity(&game->walls);
	if (game->exit != NULL)
		free_entity(&game->exit);
	if (errmsg != NULL)
		print_msg(errmsg);
	exit(exit_code);
}
