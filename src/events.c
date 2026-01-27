/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:27:02 by miricci           #+#    #+#             */
/*   Updated: 2026/01/27 13:27:05 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_events(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, on_keypress, &game->k);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, on_keyrelease, &game->k);
	mlx_loop_hook(game->mlx, loop_event, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, close_display, game);
}

// uint64_t	get_time(void)
// {
// 	struct timeval	tv;
// 	uint64_t		now;

// 	if (gettimeofday(&tv, NULL))
// 		return (printf("Error\n"), 0);		// FUNZIONE D'ERRORE
// 	now = tv.tv_sec * 1000;
// 	now += tv.tv_usec / 1000;
// 	return (now);
// }

int	on_keypress(int keycode, t_keys *k)
{
	if (keycode == XK_Escape)
		k->esc = true;
	if (keycode == W)
		k->w = true;
	if (keycode == A)
		k->a = true;
	if (keycode == S)
		k->s = true;
	if (keycode == D)
		k->d = true;
	if (keycode == LEFT)
		k->left = true;
	if (keycode == RIGHT)
		k->right = true;
	return (0);
}

int	on_keyrelease(int keycode, t_keys *k)
{
	if (keycode == XK_Escape)
		k->esc = false;
	if (keycode == W)
		k->w = false;
	if (keycode == A)
		k->a = false;
	if (keycode == S)
		k->s = false;
	if (keycode == D)
		k->d = false;
	if (keycode == LEFT)
		k->left = false;
	if (keycode == RIGHT)
		k->right = false;
	return (0);
}
int	loop_event(t_game *game)
{
	if (game->k.w == true)
		move_forward(*game->map, game->map->player);
	if (game->k.a == true)
		move_left(*game->map, game->map->player);
	if (game->k.s == true)
		move_backward(*game->map, game->map->player);
	if (game->k.d == true)
		move_right(*game->map, game->map->player);
	if (game->k.left == true)
		rotate(game->map->player, -ROT);
	if (game->k.right == true)
		rotate(game->map->player, ROT);
	render_frame(game);
	return (0);
}
