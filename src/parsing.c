/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:16:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/15 14:12:00 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_extension_valid(char *filename)
{
	int	file_len;

	file_len = ft_strlen(filename);
	if (file_len < 4 || ft_strncmp(filename + file_len - 4, ".ber", 4))
		return (false);
	return (true);
}

bool	is_map_empty(char *map)
{
	if (*map == '\0')
		return (true);
	return (false);
}

char	*read_input(const char *filename)
{
	char	*line;
	char	*line_joined;
	char	*temp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_joined = ft_calloc(1, 1);
	if (!line_joined)
	{
		close(fd);
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(line_joined, line);
		free(line_joined);
		line_joined = temp;
		free(line);
	}
	close(fd);
	return (line_joined);
}

void	parse_input(t_game *game, char *filename)
{
	t_map	*map;
	char	*map_str;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		print_msg("memory allocation failed\n");
		exit(EXIT_FAILURE);
		//display_error_exit("memory allocation for map failed.", EXIT_FAILURE);
	}
	game->map = map;
	if (is_extension_valid(filename) == false)
		free_game(game, "map extension is not valid.", EXIT_FAILURE, NULL);
	init_map(&map);
	map_str = read_input(filename);
	if (!map_str)
		free_game(game, "read_input function failed.", EXIT_FAILURE, NULL);
	if (is_map_empty(map_str) == true)
		free_game(game, "map is empty.", EXIT_FAILURE, &map_str);
	if (empty_lines_in_map(map_str) == true)
		free_game(game, "empty lines in map.", EXIT_FAILURE, &map_str);
	map->map_input = ft_split(map_str, '\n');
	if (!map->map_input)
		free_game(game, "ft_split failed.", EXIT_FAILURE, &map_str);
	populate_map_struct(map, map_str);
	if (is_map_valid(map) == false)
		free_game(game, NULL, EXIT_FAILURE, &map_str);
	free(map_str);
}
