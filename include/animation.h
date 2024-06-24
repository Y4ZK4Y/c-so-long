// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   animation.h                                        :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/06/19 13:32:34 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/19 17:25:47 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef ANIMATION_H
// # define ANIMATON_H

// #include "utils.h"
// #include "so_long"
// #include <stdlib.h>

// enum entity
// {
// 	PLAYER,
// 	ENEMY,
// 	EVENT,
// 	ENVIRONMENT,
// };

// typedef struct s_frame
// {
// 	int		x;
// 	int		y;
// 	int		color;
// 	int		figure_size;
	
// }			t_frame;

// typedef struct s_animation
// {
// 	t_list			*frames;
// 	enum entity		entity;
// 	t_frame			current_frame;
// 	int				delay;
// 	int				_tmp_delay; // delay iterator
// 	int				current_frame_num;
// 	long int		last_updated;
// 	//long int		fps;
// 	long int		frame_count;
// }					t_animation;


// typedef struct s_animator
// {
// 	t_list		*animations;
// 	t_win		*win;
// 	t_img		*img;
// }				t_animator;

// int				update(t_animator *a);
// t_animation		*ball_animation1(int delay, int fps);
// void	update_animation(void *ptr);
// void	destroy_animation(t_animation *a);
// void	init_animation(t_animation *a, enum entity entity, int delay, int fps);
// void	add_frame(t_animation *a, t_frame frame);
// void	draw_frame(void *ptr1, void *ptr2);
// void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr);
// t_list	*ft_lstget(t_list *lst, int index);


// #endif