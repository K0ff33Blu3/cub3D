/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:49:50 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 18:56:54 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_ALLOWED "01NSEW \n"

// SCREEN

# define WID 600
# define LEN 400

// KEYLOG

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define LSHIFT 65505
# define LALT 65513

// INCLUDE

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>
# include <X11/X.h>

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

// ERROR

# define ERR_ARGS "	incorrect arguments number"
# define ERR_FORMAT "	incorrect file format"
# define ERR_OPEN "	failed to open path"
# define ERR_EMPTY_OR_FOLDER "	path points to empty file or folder"
# define ERR_NEWLINE_MAP "	empty line in map"
# define ERR_OPEN_MAP "	open map"
# define ERR_NO_MAP "	missing map"
# define ERR_SPAWN "	map needs exactly ONE of the following chars: N S W E"
# define BAD_CHAR "	invalid character"
# define ERR_CHAR_FILE "	invalid character in scene description file"
# define MALLOC "	malloc failure"
# define ERR_MALLOC "malloc failure"
# define ERR_SPACE_END_PATH " trim chars at end of wall path"
# define ERR_WALL_REPEAT " wall is repeated in scene description file"
# define ERR_FC_MISS " floor or ceiling is missing in scene description file"
# define ERR_WALL_MISS "	wall is missing in scene description file"
# define ERR_FC_REPEAT " floor or ceiling is repeated in scene description file"
# define ERR_FC_FORMAT "	color format invalid"
# define ERR_FC_BOUNDS "	color value out of bounds"

typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

typedef struct s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;

}	t_player;

typedef struct s_map
{
	char		**map_skeleton;
	char		*no_text_path;
	char		*so_text_path;
	char		*ea_text_path;
	char		*we_text_path;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	int			floor_set;
	int			ceiling_set;
	int			map_width;
	int			map_height;
	t_player	*player;
	char		*tmp_line;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;

}	t_game;

int		close_display(t_game *game);

// init.c

t_game	*init_game(void);

// events.c

void	handle_events(t_game *game);
int		on_keypress(int keycode, t_game *game);

// utils_mine.c

char	*trim_back_nl(char *str);
int		skip_spaces(char *line, int count);
int		is_white(char *line);
void	free_mtx(void **mtx);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// error

void	error_msg(char *msg);
void	error_msg2(char *msg, char print_char);
void	free_map(char **map);

	// parsing map

int		parsing_map(char **map, int line, int c);
int		check_help(int *i, char *allowed);
int		check_map(char **map, int line, int count, char *allowed);
int		walls_checker(char *line, t_map *m_map);
char	**get_map(char *line, int fd, int i);

// parsing_utils

int		check_rgb_format(char *str);
int		is_file_type(const char *file, const char *type);
int		ft_mapchr(char *str, const char *map);
int		check_s_wall(char *line, char **wall);

// parsing.c

int		parse_rgb(char *str, int *rgb, int *is_set);
int		floor_celling(char *line, t_map *m_map);
int		walls_ceiling_map(char *line, char *start, t_map *m_map);
int		walls_ceiling(char *line, int fd, t_map *m_map);
int		parsing(const char *path, t_map *m_map);

#endif