/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validity.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 16:28:51 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/18 14:05:48 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


bool	empty_lines_in_map(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[0] == '\n' || (map_str[i] == '\n' && (map_str[i+1]) == '\n'))
			return (true);
		i++;
	}
	return (false);
}


bool	invalid_components(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			if (ft_strchr("PEC01X\n", map_data->map_input[i][j]) == NULL)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}