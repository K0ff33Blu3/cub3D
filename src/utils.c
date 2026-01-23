/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:06:21 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 11:42:08 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	putpixels(int x, int y, int color)
// {
// 	int	*offset;
// 	int	index;
// 	int	pixels_per_line;

// 	pixels_per_line = line_len / 4;
// 	offset = (int *)fractal->img_addr;
// 	index = y * pixels_per_line + x;
// 	offset[index] = color;
// }

void	print_map(t_map map)
{
	int i = -1;
	
	while(map.map_skeleton[++i])
		printf("%s\n", map.map_skeleton[i]);
	printf("NO_path: %s\n", map.no_text_path);
	printf("EA_path: %s\n", map.ea_text_path);
	printf("SO_path: %s\n", map.so_text_path);
	printf("WE_path: %s\n", map.we_text_path);
	printf("RGB floor: [ %d, %d, %d ]\n", map.floor_rgb[0], map.floor_rgb[1], map.floor_rgb[2]);
	printf("RGB ceiling: [ %d, %d, %d ]\n", map.ceiling_rgb[0], map.ceiling_rgb[1], map.ceiling_rgb[2]);
	// printf("map_width: %d\n", map.map_width);
	// printf("map_height: %d\n", map.map_height);
}