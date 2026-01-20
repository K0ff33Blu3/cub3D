/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:51:45 by miricci           #+#    #+#             */
/*   Updated: 2026/01/19 23:00:51 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hardcoded.h"

t_map	load_hardcoded()
{
	t_map	map;

	map.width = MAP_WID;
	map.height = MAP_HGT;
	map.skeleton = hardcoded_map;
	map.NO_text_path = NO_TEXT;
	map.EA_text_path = EA_TEXT;
	map.SO_text_path = SO_TEXT;
	map.WE_text_path = WE_TEXT;
	memset(map.floor_rgb, 0, sizeof(int) * 3);
	memset(map.ceiling_rgb, 0, sizeof(int) * 3);
	map.floor_hex = FLOOR_HEX;
	map.ceiling_hex = CEILING_HEX;
	map.player->pos.x = PLAYER_POS_X;
	map.player->pos.y = PLAYER_POS_Y;
	map.player->dir.x = PLAYER_DIR_X;
	map.player->dir.y = PLAYER_DIR_Y;
	
	return (map);
}