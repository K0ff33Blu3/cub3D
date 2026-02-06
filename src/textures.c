/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:02:57 by miricci           #+#    #+#             */
/*   Updated: 2026/02/06 14:38:02 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_tex_img(t_image *tex, t_game *game, t_map *map)
{
	tex[NO].img = mlx_xpm_file_to_image(game->mlx, map->no_text_path,
			&tex[NO].width, &tex[NO].height);
	tex[EA].img = mlx_xpm_file_to_image(game->mlx, map->ea_text_path,
			&tex[EA].width, &tex[EA].height);
	tex[SO].img = mlx_xpm_file_to_image(game->mlx, map->so_text_path,
			&(tex[SO].width), &(tex[SO].height));
	tex[WE].img = mlx_xpm_file_to_image(game->mlx, map->we_text_path,
			&tex[WE].width, &tex[WE].height);
}

void	get_tex_info(t_image *tex)
{
	tex[NO].addr = mlx_get_data_addr(tex[NO].img, &tex[NO].bpp,
			&tex[NO].line_len, &tex[NO].endian);
	tex[EA].addr = mlx_get_data_addr(tex[EA].img, &tex[EA].bpp,
			&tex[EA].line_len, &tex[EA].endian);
	tex[SO].addr = mlx_get_data_addr(tex[SO].img, &tex[SO].bpp,
			&tex[SO].line_len, &tex[SO].endian);
	tex[WE].addr = mlx_get_data_addr(tex[WE].img, &tex[WE].bpp,
			&tex[WE].line_len, &tex[WE].endian);
}

void	set_tex_to_col(t_game *game, t_column *col)
{
	if (col->wall_side == NO)
		col->tex = game->tex + NO;
	else if (col->wall_side == EA)
		col->tex = game->tex + EA;
	else if (col->wall_side == SO)
		col->tex = game->tex + SO;
	else if (col->wall_side == WE)
		col->tex = game->tex + WE;
	col->delta_tex = (double)col->tex->height / col->line_height;
	col->tex_pos.x = floor(col->wall_x * col->tex->width);
	if (col->line_height < LEN)
		col->tex_pos.y = 0;
	else
		col->tex_pos.y = floor(((col->line_height - LEN) / 2.0) * col->delta_tex);
}

unsigned int	tex_get_pixel(t_image *tex, int x, int y)
{
	unsigned int	pos;

	pos = y * tex->line_len + x * (tex->bpp / 8);
	return (*(unsigned int *)(tex->addr + pos));
}
