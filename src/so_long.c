/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:43:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 14:03:13 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(game);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(game);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(game);
	if (game->num_collectibles == 0 && \
	game->map->map_input[game->player->y][game->player->x] == 'E')
		mlx_close_window(game->mlx);
}

int	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			if (pick_entity(game, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	so_long(t_game *game)
{
	if (init(game) == 1)
		return (1);
	if (render_window(game) == 1)
		return (1);
	if (load_pngs(game) == 1)
		return ((print_msg("loading png failed.")), 1);
	if (load_images(game) == 1)
		return ((print_msg("loading images failed.")), 1);
	remove_textures(game);
	populate_game_entities(game);
	if (render_game(game) == 1)
		return (1);
	mlx_key_hook(game->mlx, &handle_key_press, game);
	mlx_loop(game->mlx);
	remove_images(game);
	return (0);
}
