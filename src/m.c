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
