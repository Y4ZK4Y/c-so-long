/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 12:26:49 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/19 13:25:02 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "MLX42.h"
#include "so_long.h"
#include <stdbool.h>

typedef struct		s_win
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*win_ptr;
	int				width;
	int				height;
}					t_win;

typedef struct s_img
{
	t_win		win;
	mlx_image_t	*img_ptr;
	int			w;
	int			h;
	//int			bpp;
	// int			endian;
	//int			line_len;
	
}				t_img;


/* window and image */
t_win	new_window(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);


#endif