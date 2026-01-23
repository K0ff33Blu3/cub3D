/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:51:45 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 13:09:56 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hardcoded.h"

t_map	*load_hardcoded()
{
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map->width = MAP_WID;
	map->height = MAP_HGT;
	int i = 0;
	map->skeleton = (char **)malloc(sizeof(char *) * MAP_HGT);
	while (i < MAP_HGT)
	{
		map->skeleton[i] = ft_strdup((char *)hardcoded_map[i]);
		i++;
	}
	map->no_text_path = NO_TEXT;
	map->ea_text_path = EA_TEXT;
	map->so_text_path = SO_TEXT;
	map->we_text_path = WE_TEXT;
	memset(map->floor_rgb, 0, sizeof(int) * 3);
	memset(map->ceiling_rgb, 0, sizeof(int) * 3);
	map->floor_hex = FLOOR_HEX;
	map->ceiling_hex = CEILING_HEX;
	map->player = (t_player *)malloc(sizeof(t_player));
	map->player->pos.x = PLAYER_POS_X;
	map->player->pos.y = PLAYER_POS_Y;
	map->player->dir.x = PLAYER_DIR_X;
	map->player->dir.y = PLAYER_DIR_Y;
	map->player->camera.x = PLAYER_CAMERA_X;
	map->player->camera.y = PLAYER_CAMERA_Y;
	
	return (map);
}