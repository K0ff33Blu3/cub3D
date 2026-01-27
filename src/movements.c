/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:00:02 by miricci           #+#    #+#             */
/*   Updated: 2026/01/27 14:27:16 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_map map, t_player *player)
{
	if (map.skeleton[(int)(player->pos.y + player->dir.y * MOV)][(int)(player->pos.x + player->dir.x * MOV)] != '1')
	{
		player->pos.x += player->dir.x * MOV;
		player->pos.y += player->dir.y * MOV;
	}
}

void	move_backward(t_map map, t_player *player)
{
	if (map.skeleton[(int)(player->pos.y + player->dir.y * MOV)][(int)(player->pos.x + player->dir.x * MOV)] != '1')
	{
		player->pos.x += -player->dir.x * MOV;
		player->pos.y += -player->dir.y * MOV;
	}
}

void	move_left(t_map map, t_player *player)
{
	if (map.skeleton[(int)(player->pos.y + player->dir.y * MOV)][(int)(player->pos.x + player->dir.x * MOV)] != '1')
	{
		player->pos.x += -player->dir.y * MOV;
		player->pos.y += +player->dir.x * MOV;
	}
}

void	move_right(t_map map, t_player *player)
{
	if (map.skeleton[(int)(player->pos.y + player->dir.y * MOV)][(int)(player->pos.x + player->dir.x * MOV)] != '1')
	{
		player->pos.x += player->dir.y * MOV;
		player->pos.y += -player->dir.x * MOV;
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
