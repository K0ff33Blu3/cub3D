/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:20:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/27 13:21:36 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/** 
 * @brief Ottieni i delta_dist
 * 
 * @param delta_dist Distanza da percorrere per raggiungere rispettivamente il lato x o y del prossimo tile
 * 
 * Il calcolo è semplificato dall'uso del valore assoluto piuttosto che una radice quadrata
 * @return t_vect Vettore delta_dist
 */

void	putpixel(t_image *img, int x, int y, int color)
{
	int	*offset;
	int	index;
	int	pixels_per_line;
	
	pixels_per_line = img->line_len / 4;
	offset = (int *)img->addr;
	index = y * pixels_per_line + x;
	offset[index] = color;
}

static double	set_wall_x(int side, t_vect hitpoint)
{
	double	wall_x;

	if (side == WE || side == EA)
		wall_x = hitpoint.y;
	else
		wall_x = hitpoint.x;
	wall_x -= floor(wall_x);
	return(wall_x);
}

t_column	get_column(t_ray *ray)
{
	t_column	col;
	
	col.line_height = LEN / ray->wall_dist;
	col.draw_start = LEN / 2 - col.line_height / 2;
	if (col.draw_start < 0)
		col.draw_start = 0;
	col.draw_end = col.line_height / 2 + LEN / 2;
	if (col.draw_end >= LEN)
		col.draw_end = LEN - 1;
	col.wall_x = set_wall_x(ray->tile_side, ray->hitpoint);
	col.wall_side = ray->tile_side;
	return (col);
}

void	put_column(t_game *game, t_column *col, int x)
{
	int	i;

	i = -1;
	while (++i < col->draw_start)
		putpixel(game->img, x, i, game->map->ceiling_hex);
	while (++i < col->draw_end)
	{
		putpixel(game->img, x, i, tex_get_pixel(col->tex, col->tex_pos.x, col->tex_pos.y));
		col->tex_pos.y +=  1.0 * col->delta_tex;
	}
	while (++i < LEN)
		putpixel(game->img, x, i, game->map->floor_hex);
}

void	render_frame(t_game *game)
{
	int	x;
	t_ray	*ray;
	
	x = 0;
	while (x < WID)
	{
		ray = init_raycasting(game->map->player, x);
		ray->hitpoint = DDA_loop(*game->map, ray);
		ray->column = get_column(ray);
		set_tex_to_col(game, &ray->column);
		put_column(game, &ray->column, x);
		free(ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}