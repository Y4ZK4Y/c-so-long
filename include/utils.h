// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   utils.h                                            :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/06/19 12:26:49 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/19 13:25:02 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef UTILS_H
// # define UTILS_H

// #include "MLX42.h"
// #include "so_long.h"
// #include <stdbool.h>

// typedef struct		s_window
// {
// 	mlx_t			*mlx_ptr;
// 	mlx_image_t		*window_ptr;
// 	int				width;
// 	int				height;
// }					t_window;

// typedef struct s_image
// {
// 	t_window		window;
// 	mlx_image_t		*image;
// 	int				width;
// 	int				height;
// }				t_image;


// /* window and image */
// t_window	new_window(int width, int height, char *str);
// t_image		new_image(int width, int height, t_window window);



// #endif