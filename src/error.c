/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:31:17 by elmondo           #+#    #+#             */
/*   Updated: 2026/02/04 15:14:08 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error_msg(char *msg)
{
	printf("Error: %s\n", msg);
}

void	error_msg2(char *msg, char print_char)
{
	printf("Error: %s %c in map\n", msg, print_char);
}

char **handle_map_error(char **map, int result)
{
	if (result == 1)
		error_msg(ERR_OPEN_MAP);
	ft_free((void **)map, -1);
	return (NULL);
}

void gnl_clear(int fd)
{
	char *line;

	if (fd < 0 || fd >= 1024)
		return;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
