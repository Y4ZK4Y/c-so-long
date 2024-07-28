/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:35:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/07/28 11:22:28 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error_exit(const char *errmsg, int exit_code)
{
	if (errmsg != NULL)
		print_msg(errmsg);
	exit(exit_code);
}

void	print_msg(const char *errmsg)
{
	write(STDOUT_FILENO, errmsg, ft_strlen(errmsg));
	write(STDOUT_FILENO, "\n", 1);
}

void	free_nullify(void **thing)
{
	free(*thing);
	*thing = NULL;
}

void	free_2d(void ***thing)
{
	int		i;
	void	**arr;

	i = 0;
	if (*thing == NULL)
		return ;
	arr = *thing;
	while (arr[i] != NULL)
	{
		free_nullify(&arr[i]);
		i++;
	}
	free(arr);
	*thing = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		free_2d((void ***)&map->map_input);
		free(map);
	}
}

void	free_entity(t_entity **entity)
{
	if ((*entity)->img != NULL)
		(*entity)->img = NULL;
	if ((*entity)->texture != NULL)
		(*entity)->texture = NULL;
	free(*entity);
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
		display_error_exit(errmsg, exit_code);
}
