/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:59:27 by miricci           #+#    #+#             */
/*   Updated: 2026/01/26 22:53:23 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	close_display(t_game *game)
{
	destroy_tex(game->tex, game);
	mlx_destroy_image(game->mlx, game->img->img);
	free(game->img);
	mlx_destroy_window(game->mlx, game->win);
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
		ft_free((void **)m_map.skeleton, -1);
		return (1);
	}
	game = init_game(&m_map);
	game->map->player = init_player(*game->map);
	game->tex = init_tex(game, game->map);
	handle_events(game);
	render_frame(game);
	mlx_loop(game->mlx);
	close_display(game);
	return (0);
}
