/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:22:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/25 14:32:15 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	destroy_tex(t_image *tex, t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (tex[i].img)
			mlx_destroy_image(game->mlx, tex[i].img);
	free(tex);
}

void	load_tex_img(t_image *tex, t_game *game, t_map *map)
{
	tex[NO].img = mlx_xpm_file_to_image(game->mlx, map->no_text_path,
			&tex[NO].width, &tex[NO].height);
	tex[EA].img = mlx_xpm_file_to_image(game->mlx, map->ea_text_path,
			&tex[EA].width, &tex[EA].height);
	tex[SO].img = mlx_xpm_file_to_image(game->mlx, map->so_text_path,
			&(tex[SO].width), &(tex[SO].height));
	tex[WE].img = mlx_xpm_file_to_image(game->mlx, map->we_text_path,
			&tex[WE].width, &tex[WE].height);
}

void	get_tex_info(t_image *tex)
{
	tex[NO].addr = mlx_get_data_addr(tex[NO].img, &tex[NO].bpp,
			&tex[NO].line_len, &tex[NO].endian);
	tex[EA].addr = mlx_get_data_addr(tex[EA].img, &tex[EA].bpp,
			&tex[EA].line_len, &tex[EA].endian);
	tex[SO].addr = mlx_get_data_addr(tex[SO].img, &tex[SO].bpp,
			&tex[SO].line_len, &tex[SO].endian);
	tex[WE].addr = mlx_get_data_addr(tex[WE].img, &tex[WE].bpp,
			&tex[WE].line_len, &tex[WE].endian);
}

t_image	*init_tex(t_game *game, t_map *map)
{
	t_image	*tex;

	tex = (t_image *)malloc(sizeof(t_image) * 4);
	if (!tex)
		return (NULL);
	load_tex_img(tex, game, map);
	if (!tex[NO].img || !tex[EA].img || !tex[SO].img || !tex[WE].img)
		return (destroy_tex(tex, game), NULL);
	printf("NO width: %d\nNO height: %d\n", tex[NO].width, tex[NO].height);
	get_tex_info(tex);
	if (!tex[NO].addr || !tex[EA].addr || !tex[SO].addr || !tex[WE].addr)
		return (destroy_tex(tex, game), NULL);
	return (tex);
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WID, LEN, "cub3D");
	game->img = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!game->img)
		return (NULL);
	game->img->img = mlx_new_image(game->mlx, WID, LEN);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp, &game->img->line_len, &game->img->endian);
	game->map = map;
	return (game);
}

t_player	*init_player(t_map map)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = get_player_pos(map.skeleton);
	player->dir = get_player_dir(map.skeleton, player->pos);
	player->camera = get_player_camera(player->dir);
	return (player);
}
