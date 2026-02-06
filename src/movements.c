/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:00:02 by miricci           #+#    #+#             */
/*   Updated: 2026/02/06 17:03:57 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	move_right(t_map map, t_player *player, double dt)
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

void	move_left(t_map map, t_player *player, double dt)
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
	player->dir.y = -tmp * sin(angle) + player->dir.y * cos(angle);
	player->camera = set_player_camera(player->dir);
}
