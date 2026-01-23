/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:06:21 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 12:30:15 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_to_hex(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	putpixel(t_game game, int x, int y, int color)
{
	int	*offset;
	int	index;
	int	pixels_per_line;

	pixels_per_line = game.line_len / 4;
	offset = (int *)game.mlx_img_addr;
	index = y * pixels_per_line + x;
	offset[index] = color;
}

/*
** Stampa la struttura t_tile
*/
void	print_tile(t_tile tile)
{
	printf("{\n\tx = %d\n\ty = %d\n}\n", tile.x, tile.y);
}

/*
** Stampa la struttura t_ray
*/
void	print_ray(t_ray ray)
{
	printf("Ray direction:\n");
	print_vect(ray.dir);
	printf("Ray tile position:\n");
	print_tile(ray.tile_pos);
	printf("Ray tile movement:\n");
	print_tile(ray.tile_mov);
	printf("Ray side distance:\n");
	print_vect(ray.side_dist);
	printf("Ray delta distance:\n");
	print_vect(ray.delta_dist);
	printf("camera_x: %f\n", ray.camera_x);
}

/*
** Stampa la struttura t_vect
*/
void	print_vect(t_vect vect)
{
	printf("{\n\tx = %f\n\ty = %f\n}\n", vect.x, vect.y);
}
/*
** Stampa la struttura t_player
*/
void	print_player(t_player player)
{
	printf("Player position:\n");
	print_vect(player.pos);
	printf("Player direction:\n");
	print_vect(player.dir);
	printf("Player camera plane:\n");
	print_vect(player.plane);
}
/*
** Stampa la struttura t_map
*/
void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		printf("%s\n", map.skeleton[i]);
		i++;
	}
	printf("NO_text_path: %s\n", map.NO_text_path);
	printf("SO_text_path: %s\n", map.SO_text_path);
	printf("EA_text_path: %s\n", map.EA_text_path);
	printf("WE_text_path: %s\n", map.WE_text_path);
	printf("floor RGB: [ %d, %d, %d ]\n", map.floor_rgb[0], map.floor_rgb[1], map.floor_rgb[2]);
	printf("ceiling RGB: [ %d, %d, %d ]\n", map.ceiling_rgb[0], map.ceiling_rgb[1], map.ceiling_rgb[2]);
	printf("map_width: %d\n", map.width);
	printf("map_height: %d\n", map.height);
	print_player(*map.player);
}
/*
** Stampa la struttura t_game
*/
void	print_game(t_game game)
{
	printf("mlx: %p\nmlx_win: %p\n", game.mlx, game.mlx_win);
	print_map(*game.map);
}