/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:59:27 by miricci           #+#    #+#             */
/*   Updated: 2026/01/30 12:55:02 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	m_map;

	if (argc != 2)
		return (error_msg(ERR_ARGS), 1);
	ft_memset(&m_map, 0, sizeof(t_map));
	if (parsing(argv[1], &m_map) != 0)
		return (destroy_map(&m_map), 1);
	game = init_game(&m_map);
	if (!game)
		return (exit(EXIT_FAILURE), 1); 
	handle_events(game);
	render_frame(game);
	mlx_loop(game->mlx);
	close_display(game);
	return (0);
}
