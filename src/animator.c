// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   animator.c                                         :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2024/06/19 13:41:27 by ykarimi       #+#    #+#                 */
// /*   Updated: 2024/06/19 13:56:06 by ykarimi       ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "animation.h"
// #include "so_long.h"




// t_list		*ft_lstget(t_list *lst, int index)
// {
// 	t_list	*n;
// 	int i;

// 	i = 0;
// 	n = lst;
// 	if (n == NULL)
// 		return (NULL);
// 	if (n->next == NULL)
// 		return (n);
// 	while (n != NULL)
// 	{
// 		if (i >= index)
// 			return (n);
// 		n = n->next;
// 		i++;
// 	}
// 	return (NULL);
// }

// void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void * ptr)
// {
// 	t_list	*temp;

// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		f(temp->content, ptr);
// 		temp = temp->next;
// 	}
// }

// static void		draw_frame(void *ptr1, void *ptr2)
// {
// 	t_animation *a;
// 	t_img	*img;
	
// 	a = (t_animation *)ptr1;
// 	img = (t_img *)ptr2;
// 	if (!a || !img)
// 		return ;
// 	if (a->fig_type == CIrCLE)
// 	{
// 		draw_circle((t_circle){
// 			a->current_frame.x;
// 			a->current_frame.y,
// 			a->current_frame.figure,
// 			a->curernt_frame.color}, *img);
// 		}
// 		else if ()
// 		{
			
// 		}
		
// }
	



// int		update(t_animator *animator)
// {
// 	if (!animator)
// 		return (1);
// 	if (animator->animations)
// 		ft_lstiter(animator->animations, update_animation);
// 	draw_rect();
// 	if (animator->animations)
// 	{
// 		ft_lstiter_param();
// 	}
// 	mlx_put_image_to_window();
// 	return (0);
// }



