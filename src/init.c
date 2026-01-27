/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:22:37 by miricci           #+#    #+#             */
/*   Updated: 2026/01/27 14:25:52 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
	game->img = (t_image *)malloc(sizeof(t_image));
	if (!game->img)
		return (NULL);
	game->img->img = mlx_new_image(game->mlx, WID, LEN);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp, &game->img->line_len, &game->img->endian);
	game->map = map;
	ft_memset(&game->k, 0, sizeof(t_keys));
	return (game);
}

t_player	*init_player(t_map map)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = set_player_pos(map.skeleton);
	player->dir = set_player_dir(map.skeleton, player->pos);
	player->camera = set_player_camera(player->dir);
	return (player);
}
