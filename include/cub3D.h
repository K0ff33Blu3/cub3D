/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:49:50 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/26 22:53:05 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_ALLOWED "01NSEW \n"

// SCREEN

# define WID	1920
# define LEN	1080

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
# include <sys/time.h>
# include <X11/X.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>
# include <stdbool.h>
# include <math.h>


# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif



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

# define MOV	0.1
# define FOV	70.0
# define ROT	0.1


typedef	enum e_side
{
	NO = 0,
	EA = 1,
	SO = 2,
	WE = 3,
} t_side;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
}	t_image;


typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

typedef struct s_tile
{
	int	x;
	int	y;
} t_tile;

typedef	struct s_column
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_vect	tex_pos;
	double	wall_x;
	double	delta_tex;
	int		wall_side;
	t_image *tex;
}	t_column;


typedef	struct s_ray
{
	t_vect	dir;
	t_tile	tile_pos;
	t_vect	side_dist;
	t_vect	delta_dist;
	double	camera_x;
	t_side	tile_side;
	t_tile	tile_mov;
	double	wall_dist;
	t_column	column;
	t_vect	hitpoint;
		// t_tile	step;
}	t_ray;

typedef struct s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	camera;
	
}	t_player;

typedef struct s_map
{
	char		**skeleton;
	char		*no_text_path;
	char		*so_text_path;
	char		*ea_text_path;
	char		*we_text_path;
	int			floor_rgb[3];
	int		floor_hex;
	int			ceiling_rgb[3];
	bool		floor_set;
	bool		ceiling_set;
	int			ceiling_hex;
	// int		width;
	// int			height;
	t_player	*player;
	char		*tmp_line;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	t_image	*img;
	void	*win;
	t_map	*map;
	t_image	*tex;
	int	*texture;

}	t_game;

int		close_display(t_game *game);
void	destroy_tex(t_image *tex, t_game *game);

// init.c

t_game	*init_game(t_map *map);
t_player	*init_player(t_map map);
t_image	*init_tex(t_game *game, t_map *map);


// events.c

void	handle_events(t_game *game);
int		on_keypress(int keycode, t_game *game);

// utils_mine.c

char	*trim_back_nl(char *str);
int		skip_spaces(char *line, int count);
int		is_white(char *line);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// error

void	error_msg(char *msg);
void	error_msg2(char *msg, char print_char);

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

int		parse_rgb(char *str, int *rgb, bool *is_set);
int		floor_celling(char *line, t_map *m_map);
int		walls_ceiling_map(char *line, char *start, t_map *m_map);
int		walls_ceiling(char *line, int fd, t_map *m_map);
int		parsing(const char *path, t_map *m_map);

void print_map(t_map map);

void	render_frame(t_game *game);

void	print_vect(t_vect vect);
void	print_player(t_player player);
void	print_map(t_map map);
void	print_game(t_game game);
void	print_tile(t_tile tile);
void	print_ray(t_ray ray);
int		rgb_to_hex(int rgb[3]);


t_vect	get_delta_distance(t_vect dir);
t_vect	get_ray_direction(t_player player, double camera_x);
t_tile	cast_vect2tile(t_vect vect);
t_vect	get_side_distance(t_vect pos, t_ray *ray);
t_ray	*init_raycasting(t_player *player, double x);
t_vect	DDA_loop(t_map map, t_ray *ray);
void	render_frame(t_game *game);
void	putpixel(t_image *img, int x, int y, int color);

t_vect get_player_camera(t_vect dir);
t_vect	get_player_dir(char **map, t_vect pos);
t_vect get_player_pos(char **map);

# include "hardcoded.h"


#endif