/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:59:27 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 11:38:47 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	close_display(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	m_map;

	if (argc != 2)
		return (error_msg(ERR_ARGS), 1);
	ft_memset(&m_map, 0, sizeof(t_map));
	if (parsing(argv[1], &m_map) != 0)
	{
		free(m_map.no_text_path);
		free(m_map.so_text_path);
		free(m_map.ea_text_path);
		free(m_map.we_text_path);
		free_mtx((void **)m_map.map_skeleton);
		return (1);
	}
	game = init_game();
	game->map = &m_map;
	print_map(*(game->map));
	handle_events(game);
	mlx_loop(game->mlx);
	close_display(game);
	return (0);
}
