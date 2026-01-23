/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:22:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 12:32:24 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WID, LEN, "cub3D");
	game->mlx_img = mlx_new_image(game->mlx, WID, LEN);
	game->mlx_img_addr = mlx_get_data_addr(game->mlx_img, &game->bits_per_pixel, &game->line_len, &game->endian);
	game->map = load_hardcoded();
	return (game);
}
