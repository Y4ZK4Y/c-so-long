/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 12:36:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/19 13:15:34 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

t_win	new_window(int w, int h, char *str)
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*win_ptr;
	
	mlx_ptr = mlx_init(w, h, "Window", false);
	win_ptr = mlx_new_image(mlx_ptr, w, h);
	mlx_image_to_window(mlx_ptr, win_ptr, 0,0);
	
	return ({mlx_ptr, win_ptr, w, h});
}

