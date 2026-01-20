/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:20:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/19 23:02:36 by miricci          ###   ########.fr       */
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
t_vect	get_delta_distance(t_vect dir)
{
	t_vect	delta_dist;
	
	if (dir.x != 0)
		delta_dist.x = fabs(1.0 / dir.x);
	else
		delta_dist.x = DBL_MAX;
	if (dir.y != 0)
		delta_dist.y = fabs(1.0 / dir.y);
	else
		delta_dist.y = DBL_MAX;
	return (delta_dist);
}

t_vect	get_ray_direction(t_player player, double camera_x)
{
	t_vect	dir;
	
	dir.x = player.dir.x + camera_x * player.plane.x;
	dir.y = player.dir.y + camera_x * player.plane.y;
	return (dir);
}

t_tile	cast_vect2tile(t_vect vect)
{
	t_tile	tile;

	tile.x = (int)vect.x;
	tile.y = (int)vect.y;
	return (tile);
}

t_vect	get_side_distance(t_vect pos, t_ray *ray)
{
	t_vect	side_dist;
	
	if (ray->dir.x < 0)
	{
		ray->tile_mov.x = -1; 
		side_dist.x = (pos.x - ray->tile_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->tile_mov.x = 1;
		side_dist.x = (ray->tile_pos.x + 1.0 - pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->tile_mov.y = -1;
		side_dist.y = (pos.y - ray->tile_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->tile_mov.y = 1;
		side_dist.y = (ray->tile_pos.y + 1.0 - pos.y) * ray->delta_dist.y;
	}
	return (side_dist);
}

t_ray	*init_raycasting(t_player *player, double x)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->camera_x = 2 * x / WID - 1;
	ray->dir = get_ray_direction(*player, ray->camera_x);
	ray->tile_pos = cast_vect2tile(player->pos);
	ray->delta_dist = get_delta_distance(ray->dir);
	ray->side_dist = get_side_distance(player->pos, ray);
	return (ray);
}

t_side	get_side(t_vect dir, bool side)
{
	if (side == true)
		if (dir.x > 0)
			return (EA);
		else
			return (WE);
	else
		if (dir.y > 0)
			return (NO);
		else
			return (SO);
}

t_vect	DDA_loop(t_map map, t_ray *ray)
{
	bool	hit;
	t_vect	hitpoint;
	
	hit = false;
	while (hit == false)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->wall_dist = ray->side_dist.x;
			ray->side_dist.x += ray->delta_dist.x;
			ray->tile_pos.x += ray->tile_mov.x;
			ray->tile_side = get_side(ray->dir, true);
		}
		else
		{
			ray->wall_dist = ray->side_dist.y;
			ray->side_dist.y += ray->delta_dist.y;
			ray->tile_pos.y += ray->tile_mov.y;
			ray->tile_side = get_side(ray->dir, false);
		}
		if (map.skeleton[ray->tile_pos.y][ray->tile_pos.x] == '1')
			hit = true;
	}
	if (ray->tile_side == NO || ray->tile_side == SO)
	{
		hitpoint.y = ray->tile_pos.y + (1 - ray->tile_mov.y) / 2;
		hitpoint.x = map.player->pos.x + ((hitpoint.y - map.player->pos.y) / ray->dir.y) * ray->dir.x;
	}
	else
	{
		hitpoint.x = ray->tile_pos.x + (1 - ray->tile_mov.x) / 2;
		hitpoint.y = map.player->pos.y + ((hitpoint.x - map.player->pos.x) / ray->dir.x) * ray->dir.y;
	}
	return (hitpoint);
}

t_column	get_draw_points(double wall_dist)
{
	t_column	col;
	
	col.line_height = LEN / wall_dist;
	col.draw_start = LEN / 2 - col.line_height / 2;
	if (col.draw_start < 0)
		col.draw_start = 0;
	col.draw_end = col.line_height / 2 + LEN / 2;
	if (col.draw_end >= LEN)
		col.draw_end = LEN - 1;
	return (col);
}

void	put_column(t_game game, t_ray ray, int x)
{
	int	i;

	i = 0;
	while (i < ray.column.draw_start)
		putpixel(game, x, i++, game.map->ceiling_hex);
	i++;
	// printf("%d\n", ray.tile_side);
	while (i < ray.column.draw_end)
		if (ray.tile_side == NO || ray.tile_side == EA)
			putpixel(game, x, i++, 0x000000);
		else
			putpixel(game, x, i++, 0xff00ff);
	i++;
	while (i < LEN)
		putpixel(game, x, i++, game.map->floor_hex);
}

double	get_distance(t_vect	origin, t_vect endpoint)
{
	double	x_dist;
	double	y_dist;
	
	x_dist = endpoint.x - origin.x;
	y_dist = endpoint.y - origin.y;
	return (sqrt(pow(x_dist, 2) + pow(y_dist, 2)));
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
		ray->column = get_draw_points(ray->wall_dist);
		put_column(*game, *ray, x);
		x++;		
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}