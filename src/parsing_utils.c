/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:52:55 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/30 17:09:09 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// /* some pathfinding algorithm? */
// bool	is_valid_path(t_map *map_data)
// {

// }


bool	is_walled(t_map *map_data)
{
	int	i = 0;
	while (i < map_data->cols)
	{
		if (*map_data->map_input[i] != 'W' || \
			map_data->map_input[map_data->rows-1][i] != 'W')
			return (false);
		i++;
	}
	i = 0;
	while (i < map_data->rows)
	{
		if (map_data->map_input[i][0] != 'W' ||\
			 map_data->map_input[i][map_data->cols-1] != 'W')
			return (false);
	}
	return (true);
}


bool	is_rectangular(t_map *map_data)
{
	int	i;
	size_t len;

	i = 0;
	len = strlen(map_data->map_input[i]);
	while (map_data->map_input[i])
	//while (i < map_data->rows)
	{
		if ((strlen(map_data->map_input[i]) != len))
			return (false);
		i++;
	}
	return (true);
}


/* counts occurance of E, C, and P */
int	count_component(t_map *map_data, int component)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < map_data->rows && map_data->map_input[i] != NULL)
	{
		while (j < map_data->cols)
		{
			if (map_data->map_input[i][j] == component)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}


int	is_map_valid(t_map *map_data)
{
	if ((count_component(map_data, 'E') != 1) || \
		(count_component(map_data, 'C') < 1) || \
				(count_component(map_data, 'P') != 1))
		return (1);
	if (is_rectangular(map_data) == false)
		return (1);
	if (is_walled(map_data) == false)
		return (1);
	// if (is_valid_path(map_data) == false)
	// 	return (1);
	return (0);
}
