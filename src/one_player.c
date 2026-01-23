/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:51:28 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/23 15:43:46 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	player_count(const char *str, const char *set)
{
	size_t	i;
	int		count;

	if (!str || !set)
		return (-1);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]))
			count++;
		i++;
	}
	return (count);
}

int	mapset_count(char **mtx, const char *set)
{
	int	count;
	int	i;

	if (!mtx || !set)
		return (-1);
	count = 0;
	i = 0;
	while (mtx[i] != NULL)
	{
		count += player_count(mtx[i], set);
		i++;
	}
	return (count);
}

int	just_one_player(char **map)
{
	const int	p_count = mapset_count(map, "NSEW");

	if (p_count < 0)
		return (1);
	if (p_count == 1)
		return (0);
	return (1);
}
