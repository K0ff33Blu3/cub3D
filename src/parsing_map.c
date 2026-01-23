/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:05:02 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/23 12:42:44 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	walls_checker(char *line, t_map *mlx)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (check_s_wall(line, &mlx->no_text_path))
			return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (check_s_wall(line, &mlx->so_text_path))
			return (1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (check_s_wall(line, &mlx->we_text_path))
			return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (check_s_wall(line, &mlx->ea_text_path))
			return (1);
	}
	return (0);
}

int	parsing_map(char **map, int line, int c)
{
	while (map[line] && !ft_mapchr(map[line], MAP_ALLOWED))
		line++;
	if (map[line] != NULL)
		return (error_msg2(BAD_CHAR, ft_mapchr(map[line], MAP_ALLOWED)), 1);
	line = 0;
	while (map[line] != NULL)
	{
		c = 0;
		while (map[line][c] != '\0')
		{
			while (map[line][c] == '1' || map[line][c] == ' ')
				c++;
			if (map[line][c] != '\0' && check_map(map, line, c, "01NSEW\0"))
				return (1);
			if (map[line][c] != '\0')
				c++;
		}
		line++;
	}
	return (0);
}

int	check_help(int *i, char *allowed)
{
	if (allowed[*i] == '\0')
		return (1);
	*i = 0;
	return (0);
}

int	check_map(char **map, int line, int count, char *allowed)
{
	int	i;

	i = 0;
	if (line == 0 || map[line + 1] == NULL || count == 0
		|| (count + 1) >= (int)ft_strlen(map[line]))
		return (1);
	if (ft_strchr("NSEW", map[line][count]))
		allowed = "01NSEW ";
	while (allowed[i] != '\0' && map[line - 1][count] != allowed[i])
		i++;
	if (check_help(&i, allowed))
		return (1);
	while (allowed[i] != '\0' && map[line + 1][count] != allowed[i])
		i++;
	if (check_help(&i, allowed))
		return (1);
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

char	**get_map(char *line, int fd, int i)
{
	char	**map;

	map = (char **)malloc(sizeof(char *));
	if (!map)
		return (error_msg(MALLOC), free(line), NULL);
	while (line)
	{
		map = ft_realloc(map, (i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		if (!map)
			return (error_msg(MALLOC), free(line), NULL);
		if (is_white(line) && !ft_strchr(line, ' '))
			return (free(line), error_msg(ERR_NEWLINE_MAP),
				ft_free((void **)map, -1), NULL);
		map[i++] = trim_back_nl(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (parsing_map(map, 0, 0) == 1)
		return (error_msg(ERR_OPEN_MAP), ft_free((void **)map, -1), NULL);
	return (map);
}
