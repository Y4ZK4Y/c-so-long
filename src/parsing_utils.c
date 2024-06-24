/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:52:55 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/24 14:18:30 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// void	dfs(t_map *map_data, int x, int y, int obstacle, int fill)
// {
// 	int n;
// 	int m;
	
// 	n = map_data->rows;
// 	m = map_data->cols;
// 	//x = map_data->
// 	if (x < 0 || y < 0 || x >= map_data->rows || y >= map_data->cols)
// 		return ;
// 	if (map_data->map_input[x][y] != background)
// 		return ;
// 	map_data->map_input[x][y] = fill;
// 	dfs(map_data, x + 1, y, background, fill);
// 	dfs(map_data, x - 1, y, background, fill);
// 	dfs(map_data, x, y + 1, background, fill);
// 	dfs(map_data, x, y - 1, background, fill);
// }

// /* floodfill for path finding */
// bool	is_valid_path(t_map *map_data)
// {
// 	int	x;
// 	int	y;
// 	x = get_pos(map_data, 'P', 'x');
// 	y = get_pos(map_data, 'P', 'y');
// 	int background = '0';

// 	if (map_data->map_input[x][y] == obstacle)
// 		return (false);
// 	dfs(map_data, x, y, background, '2');
// }




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
		return (print_msg("map has illigal components."), false);
	if ((count_component(map_data, 'E') != 1) || \
		(count_component(map_data, 'C') < 1) || \
		(count_component(map_data, 'P') != 1))
			return (print_msg("map is not a rectangle."), false);
	if (is_rectangular(map_data) == false)
		return (print_msg("map is not a rectangle."), false);
	if (is_walled(map_data) == false)
		return (print_msg("map is not surrounded by walls."), false);
	// if (is_valid_path(map_data) == false)
	//	return (print_msg("map is not playable."), false);
	return (true);
}
