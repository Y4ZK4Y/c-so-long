/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 16:27:16 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/07/28 11:37:14 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_rows(char *map_str)
{
	int	row_count;

	row_count = 0;
	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
			row_count++;
		i++;
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
