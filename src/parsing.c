/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:16:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/29 17:05:47 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	read_input(t_map	*map_data, const char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (fd = open(filename, O_RDONLY) == -1)
		return (1);
	map_data->map_input = malloc(sizeof(char *));
	if (map_data->map_input == NULL)
		return (1);
	while ((line = get_next_line(fd) != NULL))
	{
		map_data->map_input = realloc(map_data->map_input, (i + 2) *sizeof(char *));
		if (map_data->map_input == NULL)
			return (1);
		map_data->map_input[i] = line;
		if (i == 0)
			map_data->cols = strlen(line);
		i++;
	}
	map_data->rows = i;
	//map_input[i] = NULL; // null-terminatin?
	close(fd);
	return (0);
}

t_map	*init_map_data(t_map *map_data)
{
	map_data->rows = 0;
	map_data->cols = 0;
	map_data->map_input = NULL;

	return (map_data);
}

bool	is_extension_valid(char *filename)
{
	char	*map_extension;

	map_extension = strchr(filename, '.');
	if (map_extension != NULL || strncmp(map_extension + 1, "ber", 3) != 0 )
		return (false);
	return (true);
}


int	parse_input(char **argv)
{
	t_map	*map_data;

	if (!is_extension_valid(argv[1]))
		return (1);
	map_data = init_map_data(map_data);
	if (!read_input(map_data, argv[1]))
		return (1);
	if (is_map_valid(map_data))
		return (1);
	return (0);
}
