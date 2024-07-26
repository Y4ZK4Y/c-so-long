/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:52:55 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/07/26 17:12:17 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



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
			return (print_msg("component count is off."), false);
	if (is_rectangular(map_data) == false)
		return (print_msg("map is not a rectangle."), false);
	if (is_walled(map_data) == false)
		return (print_msg("map is not surrounded by walls."), false);

	flood_fill(map_data);
	return (true);
}




int	check_path(t_map *temp, int y, int x)
{
	// if (x == 7)
	// 	printf("%i\n", x);
	if (x < 0 || y < 0 || x >= temp->cols || y >= temp->rows)
		return 0;
	// printf("y: %i x: %i = %c \n", y, x, temp->map_input[y][x]);
	if (temp->map_input[y][x] == '1')
		return (0);
	if (temp->map_input[y][x] == 'C')
		temp->c--;
	if (temp->map_input[y][x] == 'E')
	{
		temp->foundE = 1;
		return (0);
	}
	temp->map_input[y][x] = '1';
	if (check_path(temp, y + 1, x) ||
		check_path(temp, y - 1, x) ||
		check_path(temp, y, x + 1) || 
		check_path(temp, y, x - 1))
			return (1);
	return (0);
}

void	flood_fill(t_map *map_data)
{
	t_map	temp;
	int	i;
	bzero(&temp, sizeof(t_map));
	temp.rows = map_data->rows;
	temp.cols = map_data->cols;
	temp.c = count_collectibles(map_data);
	int x = get_pos(map_data, 'P', 'x');
    int y = get_pos(map_data, 'P', 'y');
	temp.foundE = 0;
	temp.map_input = NULL;
	temp.map_input = (char **)malloc((temp.rows + 1) * sizeof(char *));
	if (!temp.map_input)
		print_msg("Memory allocation failed");
	i = 0;
	while (i < temp.rows)
	{
		temp.map_input[i] = ft_strdup(map_data->map_input[i]);
		i++;
	}
	temp.map_input[i] = NULL;
	check_path(&temp, y, x);
	if (!(temp.foundE == 1 && temp.c == 0))
	{
		print_msg("No valid path available");
	}
	free_2d((void ***)&temp.map_input);
}


