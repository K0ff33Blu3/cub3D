/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:09:41 by miricci           #+#    #+#             */
/*   Updated: 2026/02/05 12:42:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_side	get_side(t_vect dir, bool side)
{
	if (side == true)
	{
		if (dir.x > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (dir.y > 0)
			return (NO);
		else
			return (SO);
	}
}

static t_vect	set_hitpoint(t_vect *player, t_ray *ray)
{
	t_vect	hitpoint;

	if (ray->tile_side == NO || ray->tile_side == SO)
	{
		hitpoint.y = ray->tile_pos.y + (1 - ray->tile_mov.y) / 2;
		hitpoint.x = player->x
			+ ((hitpoint.y - player->y) / ray->dir.y) * ray->dir.x;
	}
	else
	{
		hitpoint.x = ray->tile_pos.x + (1 - ray->tile_mov.x) / 2;
		hitpoint.y = player->y
			+ ((hitpoint.x - player->x) / ray->dir.x) * ray->dir.y;
	}
	return (hitpoint);
}

t_vect	dda_loop(t_map map, t_ray *ray)
{
	bool	hit;

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
	return (set_hitpoint(&map.player->pos, ray));
}
