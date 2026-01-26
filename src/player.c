/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:36:35 by miricci           #+#    #+#             */
/*   Updated: 2026/01/23 18:03:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vect get_player_pos(char **map)
{
	int	i;
	int	j;
	t_vect	pos;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				pos.x = j;
				pos.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pos); // AGGIUNGERE CONTROLLO SU PLAYER
}

t_vect	get_player_dir(char **map, t_vect pos)
{
	t_vect	dir;
	
	if (map[(int)pos.y][(int)pos.x] == 'N')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else if (map[(int)pos.y][(int)pos.x] == 'E')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else if (map[(int)pos.y][(int)pos.x] == 'S')
	{
		dir.x = 1;
		dir.y = 0;
	}
	else
	{
		dir.x = 0;
		dir.y = -1;
	}
	return (dir);
}

double	deg_to_rad(double deg)
{
	return ((deg / 180.0) * M_PI);
}

t_vect get_player_camera(t_vect dir)
{
	t_vect camera;
	
	camera.x = tan(deg_to_rad(FOV / 2)) * dir.y;
	camera.y = -tan(deg_to_rad(FOV / 2)) * dir.x;
	return (camera);
}
