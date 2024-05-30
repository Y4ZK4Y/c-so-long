/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 10:43:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/30 17:51:32 by ykarimi       ########   odam.nl         */
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


// # define WINDOW_WIDTH
// # define WINDOW_HEIGHT

// typedef struct s_game
// {
// 	t_entity	*entities; // array of entities
// 	int			num_entities;
// 	t_input		input;
// 	t_moves		moves;
// 	t_map		map;
// 	t_sprite	walls;
// 	t_sprite	background;
// 	t_sprite	exit;
// 	t_sprite	entrance;
	

	
// }	t_game;

typedef struct s_map
{
	char		**map_input;
	int			rows;
	int			cols;
	int			tile_size;
	int			**tiles; //2d array of tile indices
	//t_sprite	*tileset; // array of tile sprites
	// int			num_tileset; // num of tile sprites
	// void		*win_ptr;
	// void		*mlx_ptr;
	
	
}			t_map;

// typedef struct s_moves
// {
	
// }       t_moves;

// typedef struct s_input
// {
// 	int key_left;
// 	int	key_right;
// 	int key_up;
// 	int key_down;
// 	int key_esc;
// 	int mouse_click;
// }	t_input;


// typedef struct s_entity
// {
// 	float	x;
// 	float	y;
// 	int		width;
// 	int		height;
// 	int		type;
// }	t_entity;



// typedef struct s_sprite
// {
// 	void	*img;
// 	int		width;
// 	int		height;
		
// }		t_sprite;



// typedef enum
// {
// 	PLAYER,
// 	ENEMY,
// 	COLLECTIBLE,
// 	WALL,
// 	ENTRANCE,
// 	EXIT,
// } EntityType;


// typedef enum
// {
// 	PLAYING,
// 	GAME_OVER,
// 	VICTORY,
// } GameState;

// // typedef enum
// // {
// // 	KEY_UP,
// // 	KEY_DOWN,
// // 	MOUSE_CLICK
// // } 


// typedef enum
// {
// 	SUCCES,
// 	ERROR_INIT,
// 	ERROR_LOAD_SPRITE,
// 	ERROR_GAME_LOOP,
// } ErrorCode;


/* Parsing */
int		parse_input(char *filename);
bool	is_extension_valid(char *filename);
int		read_input(t_map	*map_data, const char *filename);
t_map	*init_map_data(t_map *map_data);
int		is_map_valid(t_map *map_data);
int		count_component(t_map *map_data, int component);
bool	is_rectangular(t_map *map_data);
bool	is_walled(t_map *map_data);
//bool	is_valid_path(t_map *map_data);

/* error handling */
void	display_error_exit(const char *errmsg, int exit_code);


#endif