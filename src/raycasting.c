/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:06:46 by miricci           #+#    #+#             */
/*   Updated: 2026/02/05 13:08:53 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_vect	get_delta_distance(t_vect dir)
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

static t_vect	get_ray_direction(t_player player, double camera_x)
{
	t_vect	dir;

	dir.x = player.dir.x + camera_x * player.camera.x;
	dir.y = player.dir.y + camera_x * player.camera.y;
	return (dir);
}

static t_vect	get_side_distance(t_vect pos, t_ray *ray)
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
	ray->tile_pos = vect_to_tile(player->pos);
	ray->delta_dist = get_delta_distance(ray->dir);
	ray->side_dist = get_side_distance(player->pos, ray);
	return (ray);
}
