/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:12:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 16:57:38 by elmondo          ###   ########.fr       */
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

	i = ft_strlen(file);
	while (i >= 0 && file[i] != '.')
	{
		i--;
		if (i <= 0)
			return (error_msg(ERR_FORMAT), 1);
	}
	if (ft_strncmp(&file[i], type, (ft_strlen(type) + 1)) != 0)
	{
		if (ft_isspace(file[i + ft_strlen(type)]))
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
	int	i;

	i = 0;
	count = skip_spaces(line, 2);
	if (*wall)
		return (error_msg(ERR_WALL_REPEAT), 1);
	else
	{
		*wall = ft_strdup(&line[count]);
		while ((*wall)[i] && (*wall)[i] != '\n')
			i++;
		(*wall)[i] = '\0';
		if (is_file_type(*wall, ".xpm"))
			return (1);
	}
	return (0);
}

int check_rgb_format(char *str)
{
	int i;

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
