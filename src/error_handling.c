/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:35:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/11 18:50:24 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error_exit(const char *errmsg, int exit_code)
{
    
	printf("%s\n", errmsg);
	exit(exit_code);
}

static void	free_nullify(void **thing)
{
	free(*thing);
	*thing = NULL;
}


static void	free_2d(void ***thing)
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



// / Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }




void free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		free_2d((void ***)&map->map_input);
		free(map);
	}
}

void free_entity(t_entity *entity)
{
	if (entity->img != NULL)
		free(entity->img);
	if (entity->texture != NULL)
		free(entity->texture);
	free(entity);
}

void free_game(t_game *game, const char *errmsg, int exit_code)
{
	if (game->player != NULL)
		free_entity(game->player);
	if (game->collectibles != NULL)
		free_entity(game->collectibles);
	if (game->background != NULL)
		free_entity(game->background);
	if (game->walls != NULL)
		free_entity(game->walls);
	if (game->exit != NULL)
		free_entity(game->exit);
	if (game->map != NULL)
		free_map(game->map);
	display_error_exit(errmsg, exit_code);
}

// void	remove_mlx_images(t_game *game)
// {
// 	mlx_delete_image(game->mlx, game->player->img);
// 	mlx_delete_image(game->mlx, game->collectibles->img);
// 	mlx_delete_image(game->mlx, game->background->img);
// 	mlx_delete_image(game->mlx, game->walls->img);
// 	mlx_delete_image(game->mlx, game->entrance->img);
// 	mlx_delete_image(game->mlx, game->exit->img);
	
// }







