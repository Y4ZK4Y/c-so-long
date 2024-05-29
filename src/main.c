#include "so_long.h"



int main(int argc, char **argv)
{
	char	**map_input;
	char	*file_name;

	parsing(argc, argv);
	initialize_map();
	create_map();
	return 0;
}
input_validation(argc, file_name);
	map_input = read_input(file_name);
	is_map_valid(map_input, rows, cols);