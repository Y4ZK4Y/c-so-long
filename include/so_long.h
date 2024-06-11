/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 10:43:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/11 19:26:00 by ykarimi       ########   odam.nl         */
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


# define WINDOW_WIDTH 512
# define WINDOW_HEIGHT 512

#define ENTITY_WIDTH 64
#define ENTITY_HEIGHT 64

#define PIXEl_SIZE 64

typedef struct s_map
{
	char		**map_input;
	int			rows;
	int			cols;
} t_map;

typedef struct s_entity
{
	int			x;
	int			y;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	
}	t_entity;



typedef struct s_game
{
	t_map		*map;
	t_entity	*player;
	t_entity	*collectibles;
	int			num_collectibles;
	t_entity	*background;
	t_entity	*walls;
	t_entity	*exit;
	mlx_t		*mlx;
	mlx_image_t	*window;
	
}				t_game;



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



/* Initializing */
void	init_game_struct(t_game *game);
int		game_init(t_game *game);
int		init_mlx(t_game **game);
int		init_entity(t_entity **entity);
void	init_map(t_map *map);


/* Parsing */
int		parse_input(t_game *game, char *filename);
bool	is_extension_valid(char *filename);
char	*read_input(const char *filename);
int		is_map_empty(char *map_str);
int		is_empty_lines_in_map(char *map_str);
int		is_map_valid(t_map *map_data);
int		count_component(t_map *map_data, int component);
bool	is_rectangular(t_map *map_data);
bool	is_walled(t_map *map_data);
int		check_invalid_components(t_map *map_data);
int		find_cols(char *map_str);
int		find_rows(char *map_str);
//bool	is_valid_path(t_map *map_data);
void	populate_map_struct(t_map *map, char *map_str, int num_lines);


int		so_long(t_game *game);


/* error handling */
void	free_game(t_game *game, const char *errmsg, int exit_code);
void	free_entity(t_entity *entity);
void	free_map(t_map *map);
void	display_error_exit(const char *errmsg, int exit_code);
//void free_2d_array(void **array, int rows);



/* Starting the game */
int 	game_start(t_game *game);
void	populate_game_entities(t_game *game);
size_t		get_pos(t_game *game, char character, char coordinate);
int		count_collectibles(t_game *game);
void	render_elements(t_game *game);
int		load_entity(t_game *game, t_entity *entity,  const char *filepath);
void	draw_entity(t_game *game, t_entity *entity, int row, int col);
int count_lines(char *str);

//int render_window(t_game *game);
// int	load_assets(t_game *game);
// int	load_map(t_game *game);
// int	load_collectibles(t_game *game);
// int	load_player(t_game *game);


// int	load_walls(t_game *game);
// int	load_background(t_game *game);
// int	load_exit(t_game *game);
//int	load_entrance(t_game *game);

// int render_dynamic_elements(t_game *game);


// int move_right(t_game *game);
// int move_left(t_game *game);
// int move_down(t_game *game);
// int move_up(t_game *game);
void print_map_input(t_map *map);
//void	remove_mlx_images(t_game *game);
#endif

