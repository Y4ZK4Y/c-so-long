/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_validity.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 16:28:51 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/06/11 16:29:38 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



bool	is_extension_valid(char *filename)
{
	int	file_len;

	file_len = ft_strlen(filename);
	if (file_len < 4 || ft_strncmp(filename + file_len - 4, ".ber", 4))
		return (false);
	return (true);
}


int	is_map_empty(char *map)
{
	if (*map == '\0')
		return 1;
	return 0;
}

int	is_empty_lines_in_map(char *map_str)
{
    int i;

    i = 0;
    while (map_str[i])
    {
        if (map_str[0] == '\n' || (map_str[i] == '\n' && (map_str[i+1]) == '\n'))
		{
			printf("map has empty lines\n");
			return (1);
		}
        i++;
    }
    return 0;
}




int check_invalid_components(t_map *map_data)
{
    int i, j;

    for (i = 0; i < map_data->rows; i++)
    {
        for (j = 0; j < map_data->cols; j++)
        {
            if (ft_strchr("PEC01X\n", map_data->map_input[i][j]) == NULL)
            {
                printf("illegal components!\n");
                return (1);
            }
        }
    }
    return (0);
}