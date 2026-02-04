/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:12:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/02/04 18:12:56 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_mapchr(char *str, const char *map)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(map, str[i]) == NULL)
			return (str[i]);
		i++;
	}
	return (0);
}

int	is_file_type(const char *file, const char *type)
{
	int	i;
	int	type_len;

	type_len = ft_strlen(type);
	i = ft_strlen(file) - type_len;
	if (i < 0)
		return (error_msg(ERR_FORMAT), 1);
	if (ft_strncmp(&file[i], type, type_len + 1) != 0)
	{
		if (file[i + type_len] && ft_isspace(file[i + type_len]))
			error_msg(ERR_SPACE_END_PATH);
		else
			error_msg(ERR_FORMAT);
		return (1);
	}
	return (0);
}

int	check_s_wall(char *line, char **wall)
{
	int	count;
	int fd;

	count = skip_spaces(line, 2);
	if (*wall)
		return (error_msg(ERR_WALL_REPEAT), 1);
	*wall = ft_strdup(&line[count]);
	if (!*wall)
		return (error_msg(MALLOC), 1);
	*wall = trim_back_nl(*wall);
	fd = open(*wall, O_RDONLY);
	if (is_file_type(*wall, ".xpm"))
	{
		free(*wall);
		*wall = NULL;
		return (1);
	}
	if (fd < 0)
	{
		error_msg("No texture");
		return (1);
	}
	return (0);
}

int	check_rgb_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
