/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 10:43:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/10 15:04:55 by ykarimi       ########   odam.nl         */
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


# define WINDOW_WIDTH 256
# define WINDOW_HEIGHT 256

#define ENTITY_WIDTH 32
#define ENTITY_HEIGHT 32

typedef struct s_map
{
	char		**map_input;
	int			rows;
	int			cols;
	//int			tile_size;
	//int			**tiles; //2d array of tile indices
	//t_sprite	*tileset; // array of tile sprites
	// int			num_tileset; // num of tile sprites
	// void		*win_ptr;
	// void		*mlx_ptr;
	
	
} t_map;

typedef struct s_entity
{
	float			x;
	float			y;
	int				width;
	int				height;
	int				type;
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





// typedef struct s_sprite
// {
// 	void	*img;
// 	int		width;
// 	int		height;
		
// }		t_sprite;




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
int		parse_input(t_game *game, char *filename);
bool	is_extension_valid(char *filename);
char	*read_input(const char *filename);
void	init_map_data(t_map **map_data);
int		is_map_valid(t_map *map_data);
int		count_component(t_map *map_data, int component);
bool	is_rectangular(t_map *map_data);
bool	is_walled(t_map *map_data);
int		is_map_empty(char *map_str);
int		is_empty_lines_in_map(t_map *map_data, char *map_str);
int		check_invalid_components(t_map *map_data);
//bool	is_valid_path(t_map *map_data);


/* error handling */
void	display_error_exit(const char *errmsg, int exit_code);


/* Initializing */
int		so_long(t_game *game);
int		game_init(t_game *game);
//int		init_mlx(t_game *game);
//int		init_entity(t_entity **entity);


/* Starting the game */
int 	game_start(t_game *game);
void		populate_game_entities(t_game *game);
int		get_pos(t_game *game, char character, char coordinate);
int		count_collectibles(t_game *game);
void	render_elements(t_game *game);
int		load_entity(t_game *game, t_entity *entity,  const char *filepath);
void	draw_entity(t_game *game, t_entity *entity, int row, int col);


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
void	free_game(t_game *game);
void	free_entity(t_entity *entity);
void	free_map(t_map *map);
void init_main_struct(t_game *game);
//void	remove_mlx_images(t_game *game);
#endif

