/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:52:55 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/18 13:59:31 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// /* some pathfinding algorithm? */
// bool	is_valid_path(t_map *map_data);


bool	is_walled(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->cols)
	{
		if (map_data->map_input[0][i] != '1' || \
			map_data->map_input[map_data->rows-1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map_data->rows)
	{
		if (map_data->map_input[i][0] != '1' ||\
			map_data->map_input[i][map_data->cols-1] != '1')
			return (false);
		i++;
	}
	return (true);
}


bool	is_rectangular(t_map *map_data)
{
	int		i;
	size_t	len;
	size_t	line_len;

	i = 0;
	len = ft_strlen(map_data->map_input[i]);
	if (map_data->map_input[i][len - 1] == '\n')
		len--;
	while (map_data->map_input[i])
	{
		line_len = ft_strlen(map_data->map_input[i]);
		if (map_data->map_input[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != len)
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
	while (i < map_data->rows && map_data->map_input[i] != NULL)
	{
		j = 0;
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


bool	is_map_valid(t_map *map_data)
{
	if (invalid_components(map_data) == false)
		return (print_error("map has illigal components."), false);
	if ((count_component(map_data, 'E') != 1) || \
		(count_component(map_data, 'C') < 1) || \
		(count_component(map_data, 'P') != 1))
			return (print_error("map is not a rectangle."), false);
	if (is_rectangular(map_data) == false)
		return (print_error("map is not a rectangle."), false);
	if (is_walled(map_data) == false)
		return (print_error("map is not surrounded by walls."), false);
	// if (is_valid_path(map_data) == false)
	//	return (print_error("map is not playable."), false);
	return (true);
}
