
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>



bool	is_extension_valid(char *filename)
{

    int file_len;

    file_len = strlen(filename);
	if (file_len < 4  || strncmp(filename + file_len - 4 , ".ber", 4))
		return (false);
	return (true);
}


int main(int argc, char **argv)
{

    if (is_extension_valid(argv[1]) == true)
        printf("yes\n");
    else
        printf("No\n");
    return (0);
}