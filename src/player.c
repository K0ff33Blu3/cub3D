/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:36:35 by miricci           #+#    #+#             */
/*   Updated: 2026/02/05 13:13:36 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vect	set_player_pos(char **map)
{
	int		i;
	int		j;
	t_vect	pos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				pos.x = j + 0.5;
				pos.y = i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos); // AGGIUNGERE CONTROLLO SU PLAYER
}

t_vect	set_player_dir(char **map, t_vect pos)
{
	t_vect	dir;

	if (map[(int)pos.y][(int)pos.x] == 'N')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (map[(int)pos.y][(int)pos.x] == 'E')
	{
		dir.x = 1;
		dir.y = 0;
	}
	else if (map[(int)pos.y][(int)pos.x] == 'S')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else
	{
		dir.x = -1;
		dir.y = 0;
	}
	return (dir);
}

t_vect	set_player_camera(t_vect dir)
{
	t_vect	camera;

	camera.x = tan(deg_to_rad(FOV / 2)) * dir.y;
	camera.y = -tan(deg_to_rad(FOV / 2)) * dir.x;
	return (camera);
}

bool	is_walkable(t_map *map, double x, double y)
{
	t_tile	grid;
	int		map_width;
	int		map_height;

	grid.x = (int)x;
	grid.y = (int)y;
	map_width = ft_strlen(map->skeleton[grid.y]);
	map_height = array_size((void **)map->skeleton);
	if (grid.x < 0 || grid.y < 0 || grid.x >= map_width || grid.y >= map_height)
		return (false);
	return (map->skeleton[grid.y][grid.x] != '1');
}
