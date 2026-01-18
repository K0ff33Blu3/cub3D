/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 11:03:52 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 16:47:22 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*trim_back_nl(char *str)
{
	size_t	i;

	if (str[0] == '\n')
		str[0] = '\0';
	if (str[0] == '\0')
		return (str);
	i = ft_strlen(str) - 1;
	while (str[i] == '\n')
		i--;
	if (str[i + 1] == '\n')
		str[++i] = '\0';
	return (str);
}

int	skip_spaces(char *line, int count)
{
	while (line[count] == ' ' || line[count] == '\f' || line[count] == '\r'
		|| line[count] == '\t' || line[count] == '\v')
		count++;
	return (count);
}

int	is_white(char *line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		if (!ft_isspace(line[count]))
			return (0);
		count++;
	}
	return (1);
}

void	free_mtx(void **mtx)
{
	int	i;

	if (!mtx)
		return ;
	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*ret;

	if (ptr == NULL)
		return (malloc(new_size));
	else if (ptr != NULL && new_size == 0)
		return (free(ptr), NULL);
	ret = malloc(new_size);
	if (ret == NULL)
		return (NULL);
	ft_memmove(ret, ptr, old_size);
	free(ptr);
	return (ret);
}
