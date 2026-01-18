/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:12:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 10:45:14 by elmondo          ###   ########.fr       */
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

int is_file_type(const char *file, const char *type)
{
	int i;

	i = ft_strlen(file);
	while (i >= 0 && file[i] != '.')
	{
		i--;
		if (i <= 0)
			return (error_msg("	incorrect file format"), 1);
	}
	if (ft_strncmp(&file[i], type, (ft_strlen(type) + 1)) != 0)
	{
		if (ft_isspace(file[i + ft_strlen(type)]))
			error_msg("	trim chars at end of wall path");
		else
			error_msg("	incorrect file format");
		return (1);
	}
	return (0);
}
