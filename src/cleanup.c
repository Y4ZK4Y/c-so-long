/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 10:57:52 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 10:59:40 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
