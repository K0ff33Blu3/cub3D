/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:05:02 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/17 17:01:04 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	parsing_map(char **map, int line, int c)
// {
// 	while (map[line] && !ft_mapchr(map[line], MAP_ALLOWED))
// 		line++;
// 	if (map[line] != NULL)
// 		return (error_msg2("	invalid character", ft_mapchr(map[line],
// 					MAP_ALLOWED)), 1);
// 	line = 0;
// 	while (map[line] != NULL)
// 	{
// 		if (map[line][c] == '\0')
// 		{
// 			line++;
// 			c = 0;
// 		}
// 		if (map[line] == NULL)
// 			break ;
// 		while (map[line][c] == '1' || map[line][c] == ' ')
// 			c++;
// 		if (map[line][c] != '\0' && check_cross(map, line, c, "01NSEW\0"))
// 			return (1);
// 		if (map[line][c] != '\0')
// 			c++;
// 	}
// 	if (just_one_player(map) != 0)
// 		return (error_msg("	map needs exactly ONE of the following chars: N S W E"), 1);
// 	return (0);
// }
