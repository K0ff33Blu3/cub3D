/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:00:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/02/06 17:40:24 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int check_help(int *i, char *allowed)
{
	if (allowed[*i] == '\0')
		return (1);
	*i = 0;
	return (0);
}

static int check_up(char **map, int line, int count, char *allowed)
{
	int i;

	i = 0;
	if (map[line - 1][0] == '\0' || count >= (int)ft_strlen(map[line - 1]))
		return (map[line][count] != '1');
	while (allowed[i] != '\0' && map[line - 1][count] != allowed[i])
		i++;
	return (check_help(&i, allowed));
}

static int check_down(char **map, int line, int count, char *allowed)
{
	int i;

	i = 0;
	if (map[line + 1][0] == '\0' || count >= (int)ft_strlen(map[line + 1]))
		return (map[line][count] != '1');
	while (allowed[i] != '\0' && map[line + 1][count] != allowed[i])
		i++;
	return (check_help(&i, allowed));
}

static int check_sides(char **map, int line, int count, char *allowed)
{
	int i;

	i = 0;
	while (allowed[i] != '\0' && map[line][count - 1] != allowed[i])
		i++;
	if (check_help(&i, allowed))
		return (1);
	while (allowed[i] != '\0' && map[line][count + 1] != allowed[i])
		i++;
	if (allowed[i] == '\0')
		return (1);
	return (0);
}

int check_map(char **map, int line, int count, char *allowed)
{
	if (line == 0 || map[line + 1] == NULL || count == 0)
		return (1);
	if ((count + 1) >= (int)ft_strlen(map[line]))
		return (1);
	if (ft_strchr("NSEW", map[line][count]))
		allowed = "01NSEW ";
	if (check_up(map, line, count, allowed))
		return (1);
	if (check_down(map, line, count, allowed))
		return (1);
	if (check_sides(map, line, count, allowed))
		return (1);
	return (0);
}
