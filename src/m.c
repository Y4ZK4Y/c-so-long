// #include "MLX42/include/MLX42/MLX42.h"
// #include <stdio.h>
// #include <stdlib.h>

// #define WIDTH 512
// #define HEIGHT 512

// void draw_horizontal_line(mlx_image_t *image, int start, int end, int y_value, int color)
// {
// 	while (start <= end)
// 	{
// 		mlx_put_pixel(image, start, y_value, 0XFFFFFFF);
// 		start++;
// 	}
// }

// // void draw_line(mlx_image_t *image, int start_x, int start_y, int y_value, int color)
// // {
// //     int pixelX = start_x;
// //     int pixelY = start_y;
// //     while (pixels)
// //     {
// //         mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// //         pixelX += deltaX;
// //         pixelY += deltaY;
// //         --pixels;
// //     }
// // }
// // void draw_vertical_line(mlx_image_t *image, int start, int end, int x_value, int color)
// // {
// //     char *temp_x;
// // 	while (start <= end)
// // 	{
// // 		mlx_put_pixel(image, start, x_value, color);
// // 		start++;
// // 	}
// // }


// // int keypress_function(void *keypress)
// // {
// //     if ( keypress == MLX_KEY_ESCAPE)
// //     {
// //         return (0);
// //     }
// // }

// void random_func(void *param)
// {
//     mlx_t *mlx;

//     mlx = (mlx_t *)param;
//     if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
//         mlx_close_window(mlx);
// }

// int main(void)
// {
//     mlx_t   *mlx;
//     mlx_image_t *new_image;


//     if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
//     {
//         puts(mlx_strerror(mlx_errno));
//         return(EXIT_FAILURE);
//     }
   
//     new_image = mlx_new_image(mlx, HEIGHT, WIDTH);
//     mlx_put_pixel(new_image, HEIGHT/4, WIDTH/4, 0XFFFFFFF);
//     draw_horizontal_line(new_image, 100, 200, 300, 0XFFFFFFF);


//     mlx_loop_hook(mlx, &random_func, mlx);
   
//     mlx_image_to_window(mlx, new_image, 0, 0);
//     mlx_loop(mlx);

   

// }








// // put things in their right spot




// void draw_entity(t_game *game, t_entity *entity, int row, int col)
// {
//     int x = col * entity->width;
//     int y = row * entity->height;

//     mlx_image_to_window(game->mlx, entity->img, x, y);
// }




//  if (type == PLAYER)
//     {
//         // Draw player
//     }
//     else if (type == ENEMY)
//     {
//         // Draw enemy
//     }
//     else if (type == COLLECTIBLE)
//     {
//         // Draw collectible
//     }
//     else if (type == WALL)
//     {
//         // Draw wall
//     }
//     else if (type == ENTRANCE)
//     {
//         // Draw entrance
//     }
//     else if (type == EXIT)
//     {
//         // Draw exit
//     }



	

// void render_static_elements(t_game *game)
// {
//     int i, j;
//     for (i = 0; i < game->map->rows; i++)
//     {
//         for (j = 0; j < game->map->cols; j++)
//         {
//             char map_element = game->map->map_input[i][j];
//             if (map_element == '1')
//             {
//                 draw_entity(game, game->walls, i, j);
//             }
//             else if (map_element == '0')
//             {
//                 draw_entity(game, game->background, i, j);
//             }
//             else if (map_element == 'E')
//             {
//                 draw_entity(game, game->entrance, i, j);
//             }
//             else if (map_element == 'X')
//             {
//                 draw_entity(game, game->exit, i, j);
//             }
//         }
//     }
// }

// void render_dynamic_elements(t_game *game)
// {
//     int i, j;
//     for (i = 0; i < game->map->rows; i++)
//     {
//         for (j = 0; j < game->map->cols; j++)
//         {
//             char map_element = game->map->map_input[i][j];
//             if (map_element == 'P')
//             {
//                 draw_entity(game, game->player, i, j);
//             }
//             else if (map_element == 'C')
//             {
//                 draw_entity(game, game->collectibles, i, j);
//             }
//         }
//     }
// }








/* draft*/

// int	load_player(t_game *game)
// {
	
// 	game->player->texture = mlx_load_png("./res/hero_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->player->texture);
// 	if (game->player->img == NULL)
// 	{
// 		printf("loading entrance failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->player->img, 0, 0);
// 	return (0);
	
// }



// int	load_map(t_game *game)
// {
// 	if (load_background(game) == 1)
// 	{
// 		printf("RENDER background failed\n");
// 		return (1);
// 	}
// 	if (load_walls(game))
// 	{
// 		printf("RENDER background failed\n");
// 		return (1);
// 	}
// 	// if (load_entrance(game))
// 	// {
// 	// 	printf("RENDER background failed\n");
// 	// 	return (1);
// 	// }
// 	if (load_exit(game))
// 	{
// 		printf("RENDER background failed\n");
// 		return (1);
// 	}

// 	return 0;
// }



// int	load_assets(t_game *game)
// {
// 	if (load_map(game) == 1)
// 		printf("render map failed\n"); 
// 	if (load_collectibles(game))
// 	{
// 		printf("RENDER background failed\n");
// 		return (1);
// 	}
// 	if (load_player(game))
// 	{
// 		printf("RENDER player failed\n");
// 		return (1);
// 	}
// 	//render_enemy();
// 	return (0);
	
// // }


// int game_start(t_game *game)
// {
	
// 	// if (render_window(game) == 1)
//     // {
//     //     printf("render_window function failed\n");
//     //     return (1);
//     // }
// 	// if (load_assets(game) == 1)
// 	// 	printf("render assets failed\n");
    
// 	render_dynamic_elements(game);
// 	render_static_elements(game);
	

// 	// event_listerner();
// 	return 0;
// }


    // printf("Game state:\n");

    // printf("Player: x = %d, y = %d\n", game->player->x, game->player->y);
    // printf("Exit: x = %d, y = %d\n", game->exit->x, game->exit->y);

    // printf("Map: rows = %d, cols = %d\n", game->map->rows, game->map->cols);
    // for (int i = 0; i < game->map->rows; i++)
    // {
    //     for (int j = 0; j < game->map->cols; j++)
    //     {
    //         printf("%c ", game->map->map_input[i][j]);
    //     }
    //     printf("\n");
    // }


    //  printf("Game state after calling populate:\n");

//     printf("Player: x = %d, y = %d\n", game->player->x, game->player->y);
//     printf("Exit: x = %d, y = %d\n", game->exit->x, game->exit->y);

//     printf("Map: rows = %d, cols = %d\n", game->map->rows, game->map->cols);
//     for (int i = 0; i < game->map->rows; i++)
//     {
//         for (int j = 0; j < game->map->cols; j++)
//         {
//             printf("%c ", game->map->map_input[i][j]);
//         }
//         printf("\n");
//     }


// void render_elements(t_game *game)
// {
//     int i, j;
//     char map_element;
//     map_element = '\0';
//     i = 0;
//     while (i < game->map->rows)
//     {
//         j = 0;
//         while (j < game->map->cols)
//         {
//             map_element = game->map->map_input[i][j];
//             if (map_element == '1')
//             {
// 				load_entity(game, game->walls, "./res/wall.png");
//                 draw_entity(game, game->walls, i, j);
//             }
//             else if (map_element == '0')
//             {
// 				load_entity(game, game->background, "./res/background.png");
//                 draw_entity(game, game->background, i, j);
//             }
//             else if (map_element == 'E')
//             {
// 				load_entity(game, game->exit, "./res/exit.png");
//                 draw_entity(game, game->exit, i, j);
//             }
//             else if (map_element == 'P')
//             {
// 				load_entity(game, game->player, "./res/hero.png");
//                 draw_entity(game, game->player, i, j);
//             }
//             else if (map_element == 'C')
//             {
// 				load_entity(game, game->collectibles, "./res/collectible.png");
//                 draw_entity(game, game->collectibles, i, j);
//             }
//             j++;
//         }
//         i++;
//     }
// }

// int	load_walls(t_game *game)
// {
	
// 	game->walls->texture = mlx_load_png("./res/wall_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->walls->texture);
// 	if (game->walls->img == NULL)
// 	{
// 		printf("loading walls failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->walls->img, 0, 0);
// 	return (0);
	
// }


// int	load_background(t_game *game)
// {
	
// 	game->background->texture = mlx_load_png("./res/background.png");
// 	mlx_texture_to_image(game->mlx, game->background->texture);
// 	if (!game->background->img)
// 	{
// 		printf("loading background failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->background->img, 0, 0);
// 	return (0);
	
// }

// int	load_entrance(t_game *game)
// {
	
// 	game->entrance->texture = mlx_load_png("./res/walls_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->entrance->texture);
// 	if (game->entrance->img == NULL)
// 	{
// 		printf("loading entrance failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->entrance->img, 100, 100);
// 	return (0);
	
// }

// int	load_exit(t_game *game)
// {
	
// 	game->exit->texture = mlx_load_png("./res/walls_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->exit->texture);
// 	if (game->exit->img == NULL)
// 	{
// 		printf("loading exit failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->exit->img, 0, 0);
// 	return (0);
	
// }


// int	load_collectibles(t_game *game)
// {
	
// 	game->collectibles->texture = mlx_load_png("./res/enemy_cropped.png");
// 	mlx_texture_to_image(game->mlx, game->collectibles->texture);
// 	if (game->collectibles->img == NULL)
// 	{
// 		printf("loading collectibles failed\n");
// 		return (1);
// 	}
// 	//mlx_image_to_window(game->mlx, game->collectibles->img, 0, 0);
// 	return (0);
	
// }

