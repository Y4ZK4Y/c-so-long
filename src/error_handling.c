/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/29 16:35:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/05/30 17:08:36 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error_exit(const char *errmsg, int exit_code)
{
	printf("%s\n", errmsg);
	exit(exit_code);
}
