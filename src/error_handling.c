/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:35:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/29 16:36:59 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	display_exit_error(const char *errmsg, int exit_code)
{
	printf("%c\n", errmsg);
	exit(exit_code);
}
