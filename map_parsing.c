#include "so_long.h"

/* reads map input for furthur validation
	exits and cleans if error
	returns 2d array of map */
char **read_input(char *filename)
{
	char	**map_input;
	char	*line;
	int	fd;
	int i = 0;

	if (fd = open(filename, O_RDONLY) == -1)
		exit_cleanup();
	map_input = malloc(sizeof(char *));
	if (map_input == NULL)
		exit_cleanup();
	while ((line = get_next_line(fd) != NULL))
	{
		map_input = realloc(map_input, (i + 2) *sizeof(char *));
		if (map_input == NULL)
			exit_cleanup();
		map_input[i] = line;
		if (i == 0)
			cols = strlen(line);
		i++;
	}
	rows = i;
	//map_input[i] = NULL; // null-terminatin?
	close(fd);
	return map_input;
}

void	parsing(int argc, char **argv)
{
	char	**map_input;
	char	*file_name;

	input_validation(argc, file_name);
	map_input = read_input(file_name);
	is_map_valid(map_input, rows, cols);
}