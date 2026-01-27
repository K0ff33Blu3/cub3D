/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:04:24 by miricci           #+#    #+#             */
/*   Updated: 2026/01/27 14:27:36 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_tex(t_image *tex, t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (tex[i].img)
			mlx_destroy_image(game->mlx, tex[i].img);
	free(tex);
}

void	destroy_map(t_map *map)
{
	ft_free((void **)map->skeleton, -1);
	free(map->no_text_path);
	free(map->so_text_path);
	free(map->ea_text_path);
	free(map->we_text_path);
}

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

