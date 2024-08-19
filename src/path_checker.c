/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/19 11:32:53 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 11:42:09 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_map *temp, int y, int x)
{
	if (x < 0 || y < 0 || x >= temp->cols || y >= temp->rows)
		return (0);
	if (temp->map_input[y][x] == '1')
		return (0);
	if (temp->map_input[y][x] == 'C')
		temp->c--;
	if (temp->map_input[y][x] == 'E')
	{
		temp->found_e = 1;
		return (0);
	}
	temp->map_input[y][x] = '1';
	if (check_path(temp, y + 1, x) || check_path(temp, y - 1, x) \
	|| check_path(temp, y, x + 1) || check_path(temp, y, x - 1))
		return (1);
	return (0);
}

bool	flood_fill(t_map *map_data)
{
	t_map	temp;
	int		i;
	int		x;
	int		y;

	i = -1;
	ft_bzero(&temp, sizeof(t_map));
	temp.rows = map_data->rows;
	temp.cols = map_data->cols;
	temp.c = count_collectibles(map_data);
	x = get_pos(map_data, 'P', 'x');
	y = get_pos(map_data, 'P', 'y');
	temp.map_input = malloc((temp.rows + 1) * sizeof(char *));
	if (!temp.map_input)
		return (print_msg("Memory allocation failed"), false);
	while (++i < temp.rows)
		temp.map_input[i] = ft_strdup(map_data->map_input[i]);
	temp.map_input[i] = NULL;
	check_path(&temp, y, x);
	if (!(temp.found_e == 1 && temp.c == 0))
		return (free_2d((void ***)&temp.map_input), false);
	free_2d((void ***)&temp.map_input);
	return (true);
}
