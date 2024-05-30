/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 15:53:07 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/30 17:45:49 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	if (argc != 2)
		display_error_exit("few arguments provided.", EXIT_FAILURE);
	if (!parse_input(argv[1]))
		display_error_exit("parsing failed.", EXIT_FAILURE);
	

	return (0);
}
