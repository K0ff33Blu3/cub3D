/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:27:02 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 14:27:12 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_events(t_game *game)
{
	mlx_key_hook(game->mlx_win, on_keypress, game);
	mlx_hook(game->mlx_win, DestroyNotify, NoEventMask, close_display, game);
}

void	move_forward(t_map map, t_player *player)
{
	(void)map;
	player->pos.x = player->dir.x * MOV;
	player->pos.y = player->dir.y * MOV;
}

void	move_backward(t_map map, t_player *player)
{
	(void)map;
	player->pos.x = -player->dir.x * MOV;
	player->pos.y = -player->dir.y * MOV;
}

void	move_left(t_map map, t_player *player)
{
	(void)map;
	
	player->pos.x = -player->dir.y * MOV;
	player->pos.y = -player->dir.x * MOV;
}

void	move_right(t_map map, t_player *player)
{
	(void)map;
	player->pos.x = player->dir.y * MOV;
	player->pos.y = player->dir.x * MOV;
}

int	on_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_display(game);
	// if (keycode == W)
	// {
	// 	move_forward(*game->map, game->map->player);
	// 	printf("%d\n", keycode);
	// }
	// if (keycode == A)
	// 	move_left(*game->map, game->map->player);
	// if (keycode == S)
	// 	move_backward(*game->map, game->map->player);
	// if (keycode == D)
	// 	move_right(*game->map, game->map->player);
	render_frame(game);
	return (0);
}
