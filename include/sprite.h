/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 17:26:56 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/19 17:32:44 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
#define SPRITE_H

#include "so_long.h"
#include "animation.h"



typedef struct s_sprite
{
	t_list		*animations;
	char		*name;
	char		*file_path;
	t_img		sprite_img;
	int			width;
	int			height;
	int			z_index;
	
}				t_sprite;

typedef struct sprite_slice
{
	int	x;
	int	y;
	int	width;
	int	height;
	
}			sprite_slice;


t_sprite		new_prite(char *name, char *file_path, t_win *window);
t_animation		*slice_sprite(t_sprite s, sprite_slice slice_sprite, int frames, int delay);

void		destroy_sprite(t_sprite s);


#endif