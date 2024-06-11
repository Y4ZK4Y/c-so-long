/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:16:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/11 19:32:18 by ykarimi       ########   odam.nl         */
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
	{
		close(fd);
		return NULL;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strjoin(line_joined, line);
			free(line_joined);
            line_joined = temp;
            free(line);
		}
		else
			break;
	}
	close(fd);
	return (line_joined);
}


// static void print_map_grid(char **map_grid) {
//     if (map_grid == NULL) {
//         printf("map_grid is NULL\n");
//         return;
//     }

//     for (int i = 0; map_grid[i] != NULL; i++) {
//         printf("%s\n", map_grid[i]);
//     }
// }




int	parse_input(t_game *game, char *filename)
{
	t_map	*map;
	char	*map_str;
	int num_lines;
	//char	**map_grid;
	
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		printf("memory allocation for map failed\n");
		return (1);
	}
	init_map(map);
	if (is_extension_valid(filename) == false)
	{
		free_map(map);
		printf("ext_checker failed\n");
		return (1);
	}
	map_str = read_input(filename);
	if (map_str == NULL)
	{
		free_map(map);
		printf("read_input function failed\n");
		return (1);
	}
	if (is_map_empty(map_str) == 1)
	{
		free_map(map);
		printf("map empty\n");
		free(map_str);
		return (1);
	}
	printf("77777777777\n");
	if (is_empty_lines_in_map(map_str) == 1)
	{
		printf("empty line in map\n");
		free_map(map);
		free(map_str);
		return 1;
	}
	num_lines = count_lines(map_str);
	map->map_input = ft_split(map_str, '\n');
	if (map->map_input == NULL)
	{
		printf("ft_split failed\n");
		free_map(map);
		free(map_str);
		return 1;
	}
	populate_map_struct(map, map_str, num_lines);
	game->map = map;
	printf("77777777777\n");
	if (is_map_valid(map) == 1)
	{
		printf("is map valid failed\n");
		free(map_str);
		free_map(map);
		return (1);
	}
	
	printf("rows: %d\n", game->map->rows);
	printf("cols: %d\n", game->map->cols);
	print_map_input(game->map);

	
	printf("succes in parse_input\n");
	free(map_str);
	return (0);
}
