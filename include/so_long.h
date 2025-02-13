/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 10:43:26 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/08/19 14:03:55 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# define WINDOW_WIDTH 512
# define WINDOW_HEIGHT 512
# define ENTITY_WIDTH 64
# define ENTITY_HEIGHT 64
# define PIXEL_SIZE 64

typedef struct s_map
{
	char		**map_input;
	int			rows;
	int			cols;
	int			c;
	int			found_e;
}				t_map;

typedef struct s_entity
{
	int				x;
	int				y;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}					t_entity;

typedef struct s_game
{
	t_map			*map;
	t_entity		*player;
	t_entity		*collectibles;
	int				num_collectibles;
	t_entity		*background;
	t_entity		*walls;
	t_entity		*exit;
	mlx_t			*mlx;
	mlx_image_t		*window;
	int				num_moves;
}				t_game;

/* Initializing */
void		init_game_struct(t_game *game);
void		init_map(t_map **map);
int			init(t_game *game);
int			init_mlx(t_game *game);
void		init_entity(t_entity **entity);

/* Parsing */
void		parse_input(t_game *game, char *filename);
bool		is_extension_valid(char *filename);
char		*read_input(const char *filename);

/* Map validity */
bool		is_map_empty(char *map_str);
bool		empty_lines_in_map(char *map_str);
bool		is_map_valid(t_map *map_data);
int			count_component(t_map *map_data, int component);
bool		is_rectangular(t_map *map_data);
bool		is_walled(t_map *map_data);
bool		invalid_components(t_map *map_data);
bool		flood_fill(t_map *map_data);
int			check_path(t_map *temp, int y, int x);

/* Populating the map */
int			find_cols(char *map_str);
int			find_rows(char *map_str);
void		populate_map_struct(t_map *map, char *map_str);

/* Starting the game */
int			so_long(t_game *game);
int			render_window(t_game *game);
int			load_pngs(t_game *game);
int			load_images(t_game *game);
void		populate_game_entities(t_game *game);
int			get_pos(t_map *map, char character, char coordinate);
int			count_collectibles(t_map *map);
int			render_game(t_game *game);
int			draw_entity(t_game *game, t_entity *entity, int x, int y);
int			pick_entity(t_game *game, int i, int j);

/* Move Functions */
void		handle_key_press(mlx_key_data_t keydata, void *param);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);

/* Error handling */
void		free_game(t_game *game, const char *errmsg, int exit_code, \
														char **str);
void		free_entity(t_entity **entity);
void		free_map(t_map *map);
void		remove_textures(t_game *game);
void		remove_images(t_game *game);
void		print_msg(const char *errmsg);
void		free_nullify(void **thing);
void		free_2d(void ***thing);

#endif
