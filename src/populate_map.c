/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 16:27:16 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/12 10:53:34 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int find_rows(char *map_str)
{
    int row_count = 0;
    for (int i = 0; map_str[i] != '\0'; i++) {
        if (map_str[i] == '\n') {
            row_count++;
        }
    }
    return row_count + 1;
}

int find_cols(char *map_str)
{
    int col_count = 0;
    while (map_str[col_count] != '\n' && map_str[col_count] != '\0') {
        col_count++;
    }
    return col_count;
}

int count_lines(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    return (count+1);
}

void print_map_input(t_map *map)
{
    printf("Map input:\n");

    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; map->map_input[i][j] != '\0'; j++)
        {
            printf("%c ", map->map_input[i][j]);
        }
        printf("\n");
    }
}


void	populate_map_struct(t_map *map, char *map_str, int num_lines)
{
	map->rows = find_rows(map_str);
	map->cols = find_cols(map_str);
    // printf("uurows: %d\n", map->rows);
	// printf("uucols: %d\n", map->cols);
    // print_map_input(map);
}
