/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:16:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 13:09:06 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	*read_input(const char *filename)
{
	char	*line;
	char	*line_joined;
	char *temp;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	line_joined = calloc(1, 1);
	if (!line_joined)
		return NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			
			temp= ft_strjoin(line_joined, line);
			free(line_joined);
			line_joined = temp;
			free(line);
			line = NULL;
		}
		else
			break;
	}
	//printf("<%s>\n", line_joined);
	close(fd);
	return (line_joined);
}




void	init_map_data(t_map **map_data)
{
	(*map_data)->map_input = NULL;
	(*map_data)->rows = 0;
	(*map_data)->cols = 0;
	//map_data->tile_size = 0;
	//map_data->tiles = NULL;

}
static void find_cols(t_map *map_data)
{
    int col_count = 0;

    while (map_data->map_input[col_count] != NULL)
    {
        col_count++;
    }

    map_data->rows = col_count;
}

static void find_rows(t_map *map_data)
{
    int row_count = 0;

    if (map_data->map_input[0] != NULL)
    {
        row_count = strlen(map_data->map_input[0]);
    }

    map_data->cols = row_count;
}


bool	is_extension_valid(char *filename)
{
	int	file_len;

	file_len = strlen(filename);
	if (file_len < 4 || strncmp(filename + file_len - 4, ".ber", 4))
		return (false);
	return (true);
}


int	parse_input(t_game *game, char *filename)
{
	t_map	*map_data;
	char	*map_str;

	map_data = malloc(sizeof(t_map));
	if (map_data == NULL)
	{
		printf("mallocing for map failed inside parse-input\n");
		return (1);
	}
	
	if (is_extension_valid(filename) == false)
	{
		printf("ext failed\n");
		free_map(map_data);
		return (1);
	}
		
	
	init_map_data(&map_data);
	

	map_str = read_input(filename);
	
	if (map_str == NULL)
	{
		printf("map_str failed\n");
		free_map(map_data);
		return (1);
	}
	

	if (is_map_empty(map_str) == 1)
	{
		printf("map empty\n");
		free_map(map_data);
		free(map_str);
		//map_str = NULL;
		return (1);
	}
	if (is_empty_lines_in_map(map_data, map_str) == 1)
	{
		printf("empty line in map\n");
		free(map_str);
		map_str = NULL;
		free_map(map_data);
		return 1;
		
	}

	map_data->map_input = ft_split(map_str, '\n');
	if (map_data->map_input == NULL)
	{
		printf("ft_split failed\n");
		free(map_str);
		map_str = NULL;
		free_map(map_data);
		return 1;
	}
	
	find_rows(map_data);
	find_cols(map_data);
	if (is_map_valid(map_data) == 1)
	{
		printf("is map valid failed\n");
		free(map_str);
		map_str = NULL;
		free_map(map_data);
		return (1);
	}
	game->map = map_data;
	printf("succes in parse_input\n");
	free(map_str);
	//map_str = NULL;
	return (0);
}
