/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 16:27:16 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/20 21:43:42 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	find_rows(char *map_str)
{
	int	row_count;

	row_count = 0;
	for (int i = 0; map_str[i] != '\0'; i++)
	{
		if (map_str[i] == '\n')
			row_count++;
	}
	return (row_count + 1);
}

int	find_cols(char *map_str)
{
	int	col_count;

	col_count = 0;
	while (map_str[col_count] != '\n' && map_str[col_count] != '\0')
		col_count++;
	return (col_count);
}


void	populate_map_struct(t_map *map, char *map_str)
{
	map->rows = find_rows(map_str);
	map->cols = find_cols(map_str);
}


// bool	is_accessible(t_map *map_data, int target_x, int target_y, char *obstacle)
// {
//     int	x;
//     int	y;

//     x = get_pos(map_data, 'P', 'x');
//     y = get_pos(map_data, 'P', 'y');

//     if (x == target_x && y == target_y)
//         return (true);

//     if (map_data->map_input[x][y] == obstacle)
//         return (false);

//     map_data->map_input[x][y] = obstacle;

//     return is_accessible(map_data, target_x, target_y, obstacle) ||
//         is_accessible(map_data, target_x, target_y, obstacle) ||
//         is_accessible(map_data, target_x, target_y, obstacle) ||
//         is_accessible(map_data, target_x, target_y, obstacle);
// }

// bool	is_valid_path(t_map *map_data)
// {
//     int	x;
//     int	y;

//     for (x = 0; x < map_data->rows; x++)
//     {
//         for (y = 0; y < map_data->cols; y++)
//         {
//             if (map_data->map_input[x][y] == 'C' || map_data->map_input[x][y] == 'E')
//             {
//                 if (!is_accessible(map_data, x, y, '1'))
//                     return (false);
//             }
//         }
//     }

//     return (true);
// }