/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:04:24 by miricci           #+#    #+#             */
/*   Updated: 2026/02/05 12:40:34 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_tex(t_image *tex, t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (tex[i].img)
			mlx_destroy_image(game->mlx, tex[i].img);
	free(tex);
}

void	destroy_map(t_map *map)
{
	if (map->skeleton)
		ft_free((void **)map->skeleton, -1);
	else if (map->tmp_line)
		free(map->tmp_line);
	free(map->no_text_path);
	free(map->so_text_path);
	free(map->ea_text_path);
	free(map->we_text_path);
}

int	close_display(t_game *game)
{
	if (game->map)
		destroy_map(game->map);
	if (game->map->player)
		free(game->map->player);
	if (game->tex)
		destroy_tex(game->tex, game);
	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(EXIT_SUCCESS);
}
