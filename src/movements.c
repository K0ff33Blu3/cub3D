/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:00:02 by miricci           #+#    #+#             */
/*   Updated: 2026/01/30 11:29:18 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_walkable(t_map *map, double x, double y)
{
	t_tile grid;
	int	map_width;
	int	map_height;

	grid.x = (int)x;
	grid.y = (int)y;
	map_width = ft_strlen(map->skeleton[grid.y]);
	map_height = array_size((void **)map->skeleton);
	if (grid.x < 0 || grid.y < 0 || grid.x >= map_width || grid.y >= map_height)
		return (false);
	return (map->skeleton[grid.y][grid.x] != '1');	
}

void	move_forward(t_map map, t_player *player, double dt)
{
	t_vect	new;

	new.x = player->pos.x + player->dir.x * (MOV * dt);
	new.y = player->pos.y + player->dir.y * (MOV * dt);
	if (is_walkable(&map, new.x, new.y))
	{
		player->pos.x = new.x;
		player->pos.y = new.y;
	}
}

void	move_backward(t_map map, t_player *player, double dt)
{
	t_vect	new;

	new.x = player->pos.x - player->dir.x * (MOV * dt);
	new.y = player->pos.y - player->dir.y * (MOV * dt);
	if (is_walkable(&map, new.x, new.y))
	{
		player->pos.x = new.x;
		player->pos.y = new.y;
	}
}

void	move_left(t_map map, t_player *player, double dt)
{
	t_vect	new;

	new.x = player->pos.x - player->dir.y * (MOV * dt);
	new.y = player->pos.y + player->dir.x * (MOV * dt);
	if (is_walkable(&map, new.x, new.y))
	{
		player->pos.x = new.x;
		player->pos.y = new.y;
	}
}

void	move_right(t_map map, t_player *player, double dt)
{
	t_vect	new;

	new.x = player->pos.x + player->dir.y * (MOV * dt);
	new.y = player->pos.y - player->dir.x * (MOV * dt);
	if (is_walkable(&map, new.x, new.y))
	{
		player->pos.x = new.x;
		player->pos.y = new.y;
	}
}

void	rotate(t_player *player, double angle)
{
	double	tmp;

	tmp = player->dir.x;
	player->dir.x = tmp * cos(angle) + player->dir.y * sin(angle);
	player->dir.y = - tmp * sin(angle) + player->dir.y * cos(angle);
	player->camera = set_player_camera(player->dir);
}
