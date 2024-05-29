#include "so_long"


bool	is_rectangular(char **input, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (strlen(input[i] != cols))
			return false;
		i++;
	}
	return true;
}

bool	is_walled(char **input, int rows, int cols)
{
	int	i;
	while (i < cols)
	{
		if (input[i] != 'W' || input[rows-1][i] != 'W')
			return false;
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (input[i][0] != 'W' || input[i][cols-1] != )
			return false;
	}
	return true;
}

/* some pathfinding algorithm? */
bool	is_valid_path()
{

}
/* counts occurance of E, C, and P */
int	count_component(char **input, int rows, int cols, char *component)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < rows && input[i] != NULL)
	{
		while (j < cols)
		{
			if (input[i][j] == component)
				count++;
			j++;
		}
		i++;
	}
	return count;
}


/* checks map rules 
	exits and cleans if invalid */
void	is_map_valid(char **input, int rows, int cols)
{
	
	if (count_component(input, rows, cols, "E") != 1 || count_component(input, rows, cols, "C" < 1) \
					|| count_component(input, rows, cols, "P") != 1)
		printf("Error\n"); //exit_cleanup();
	if (is_rectangular() == false)
		printf("Error\n"); //exit_cleanup();
	if (is_walled() == false)
		printf("Error\n"); //exit_cleanup();
	if (is_valid_path() == false)
	// printf("Error\n"); /exit_cleanup();
}

/* exit and clean if input not valid 
	checks argc and extension */
void	input_validation(int argc, char *filename)
{
	char	*map_extension;

	if (argc == )
		exit_cleanup();
	map_extension = strchr(filename, '.');
	if (map_extension != NULL || strcmp(map_extension + 1, "ber") != 0)
		exit_cleanup();
}