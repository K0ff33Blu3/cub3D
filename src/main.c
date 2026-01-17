/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:59:27 by miricci           #+#    #+#             */
/*   Updated: 2026/01/17 15:29:22 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_display(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_game	*game;

	game = init_game();
	handle_events(game);
	mlx_loop(game->mlx);
	close_display(game);
	return (0);
}