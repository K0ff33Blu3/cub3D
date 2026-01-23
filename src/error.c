/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:31:17 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/23 16:06:52 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
}

void	error_msg2(char *msg, char print_char)
{
	printf("Error\n%s %c in map\n", msg, print_char);
}

char **handle_map_error(char **map, int result)
{
	if (result == 1)
		error_msg(ERR_OPEN_MAP);
	ft_free((void **)map, -1);
	return (NULL);
}
