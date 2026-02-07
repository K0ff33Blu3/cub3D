/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:06:21 by miricci           #+#    #+#             */
/*   Updated: 2026/02/07 12:21:55 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_to_hex(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

t_tile	vect_to_tile(t_vect vect)
{
	t_tile	tile;

	tile.x = floor(vect.x);
	tile.y = floor(vect.y);
	return (tile);
}

double	deg_to_rad(double deg)
{
	return ((deg / 180.0) * M_PI);
}

char	*trim_back_nl(char *str)
{
	size_t	i;

	if (str[0] == '\0')
		return (str);
	i = ft_strlen(str) - 1;
	while (i > 0 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		i--;
	if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		str[i] = '\0';
	else
		str[i + 1] = '\0';
	return (str);
}

int	is_white(char *line)
{
	int		count;

	count = 0;
	while (line[count])
	{
		if (!ft_isspace(line[count]))
			return (0);
		count++;
	}
	return (1);
}
