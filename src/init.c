/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:22:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/17 15:28:19 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game	*init_game(void)
{
	t_game	*game;
	
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, WID, LEN, "cub3D");
	return (game);
}
