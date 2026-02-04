/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:03:20 by elmondo           #+#    #+#             */
/*   Updated: 2026/02/04 17:38:07 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int parse_rgb(char *str, int *rgb, bool *is_set, int *hex)
{
	char **values;
	int i;

	if (*is_set == true)
		return (error_msg(ERR_FC_REPEAT), 1);
	values = ft_split(str, ',');
	if (!values)
		return (error_msg(MALLOC), 1);
	i = 0;
	while (values[i])
		i++;
	if (i != 3 || !check_rgb_format(values[0]) || !check_rgb_format(values[1]) || !check_rgb_format(values[2]))
		return (ft_free((void **)values, -1), error_msg(ERR_FC_FORMAT), 1);
	rgb[0] = ft_atoi(values[0]);
	rgb[1] = ft_atoi(values[1]);
	rgb[2] = ft_atoi(values[2]);
	ft_free((void **)values, -1);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (error_msg(ERR_FC_BOUNDS), 1);
	*hex = rgb_to_hex(rgb);
	*is_set = true;
	return (0);
}

int floor_ceiling(char *line, t_map *m_map)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_rgb(&line[i], m_map->floor_rgb, &m_map->floor_set, &m_map->floor_hex));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_rgb(&line[i], m_map->ceiling_rgb, &m_map->ceiling_set, &m_map->ceiling_hex));
	return (0);
}

int walls_ceiling_map(char *line, char *start, t_map *m_map)
{
	if ((ft_strncmp(line, "NO ", 3) == 0) || (ft_strncmp(line, "SO ", 3) == 0) || (ft_strncmp(line, "WE ", 3) == 0) || (ft_strncmp(line, "EA ", 3) == 0))
	{
		if (walls_checker(line, m_map))
			return (1);
	}
	else if ((ft_strncmp(line, "F ", 2) == 0) || (ft_strncmp(line, "C ", 2) == 0))
	{
		if (floor_ceiling(line, m_map))
			return (1);
	}
	else if (*line == '1' || *line == '0' || *line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		m_map->tmp_line = start;
		return (2);
	}
	else
		return (error_msg(ERR_CHAR_FILE), 1);
	return (0);
}

int walls_ceiling(char *line, int fd, t_map *m_map)
{
	char *start;
	int result;

	while (line)
	{
		while (line && is_white(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (!line)
			break;
		start = line;
		while (*line == ' ' || *line == '\t')
			line++;
		result = walls_ceiling_map(line, start, m_map);
		if (result == 1)
			return (free(start), 1);
		if (result == 2)
			return (0);
		free(start);
		line = get_next_line(fd);
	}
	return (0);
}

int parsing(const char *path, t_map *m_map)
{
	int fd;
	char **map;
	char *line;

	if (is_file_type(path, ".cub"))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg(ERR_OPEN), 1);
	line = get_next_line(fd);
	if (walls_ceiling(line, fd, m_map) != 0)
		return (gnl_clear(fd), close(fd), 1);
	if (!m_map->floor_set || !m_map->ceiling_set)
		return (error_msg(ERR_FC_MISS), gnl_clear(fd), close(fd), 1);
	if (m_map->no_text_path == NULL || m_map->so_text_path == NULL || m_map->ea_text_path == NULL || m_map->we_text_path == NULL)
		return (error_msg(ERR_WALL_MISS), gnl_clear(fd), close(fd), 1);
	if (!m_map->tmp_line)
		return (error_msg(ERR_NO_MAP), gnl_clear(fd), close(fd), 1);
	map = get_map(m_map->tmp_line, fd, 0);
	m_map->tmp_line = NULL;
	if (map == NULL)
		return (1);
	m_map->skeleton = map;
	close(fd);
	return (0);
}
