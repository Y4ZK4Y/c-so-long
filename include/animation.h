/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 13:32:34 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/19 17:25:47 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATON_H

#include "utils.h"
#include "so_long"
#include <stdlib.h>

enum entity
{
	PALYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_frame
{
	int		x;
	int		y;
	int		color;
	int		figure_size;
	
}			t_frame;

typedef struct s_animation
{
	t_list			*frames;
	enum entity		entity;
	t_frame			current_frame;
	int				delay;
	int				_tmp_delay;
	int				current_frame_num;
	long int		last_updated;
	//long int		fps;
	long int		frame_count;
}					t_animation;


typedef struct s_animator
{
	t_list		*animations;
	t_win		*win;
	t_img		*img;
}				t_animator;

int				update(t_animator *a);
t_animation		*ball_animation1(int delay, int fps);

#endif