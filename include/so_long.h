/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 10:43:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/29 17:11:58 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "MLX42.h"
#include "get_next_line.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>


# define constants
# define constants

typedef struct s_game
{
	
}       t_game;

typedef struct s_map
{
	char	**map_input;
	int		rows;
	int		cols;
	
	
}       t_map;

typedef struct s_moves
{
	
}       t_moves;


/* Parsing */
int	parse_input(char **argv);
bool	is_extension_valid(char *filename);
t_map	*init_map_data(t_map *map_data);
int	read_input(t_map	*map_data, const char *filename);
int	is_map_valid(t_map *map_data);
int	count_component(t_map *map_data, char *component);
bool	is_rectangular(t_map *map_data);
bool	is_walled(t_map *map_data);
bool	is_valid_path(t_map *map_data);

/* error handling */
void	display_exit_error(const char *errmsg, int exit_code);


#endif