/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:16:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/31 13:34:30 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	read_input(t_map *map_data, const char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (1);
	map_data->map_input = malloc(sizeof(char *));
	if (map_data->map_input == NULL)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		map_data->map_input = realloc(map_data->map_input, (i + 2) *sizeof(char *));
		if (map_data->map_input == NULL)
			return (1);
		map_data->map_input[i] = line;
		if (i == 0)
		{
			map_data->cols = strlen(line);
			 if (line[map_data->cols - 1] == '\n')
        map_data->cols--;
		}
		i++;
	}
	map_data->rows = i;
	map_data->map_input[i] = NULL; // null-terminatin?
	//printf("map_data->map_input[%d] = %p\n", i, (void *)map_data->map_input[i]);
	close(fd);

	// for (int k = 0; map_data->map_input[k] != NULL; k++)
	// {
	// 	printf("%s\n", map_data->map_input[k]);
	// }
	return (0);
}

t_map	*init_map_data(t_map *map_data)
{
	map_data->map_input = NULL;
	map_data->rows = 0;
	map_data->cols = 0;
	//map_data->tile_size = 0;
	//map_data->tiles = NULL;
	

	return (map_data);
}

bool	is_extension_valid(char *filename)
{
	int	file_len;

	file_len = strlen(filename);
	if (file_len < 4 || strncmp(filename + file_len - 4, ".ber", 4))
		return (false);
	return (true);
}


int	parse_input(char *filename)
{
	t_map	*map_data;

	map_data = NULL;
	if (is_extension_valid(filename) == false)
		return (1);
	map_data = malloc(sizeof(t_map));
	if (map_data == NULL)
		return (1);
	map_data = init_map_data(map_data);
	if (read_input(map_data, filename) == 1)
	{
		printf("exit thing\n");
		return (1);
	}
		
	if (is_map_valid(map_data) == 1)
	{
		printf("is map valid failed\n");
		return (1);
	}
	printf("succes in parse_input\n");
	return (0);
}
