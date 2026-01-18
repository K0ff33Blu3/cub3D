/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:49:50 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/18 22:33:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_ALLOWED "01NSEW \n"

// SCREEN

# define WID	1920
# define LEN	1080

// KEYLOG


#define W 119
#define S 115
#define A 97
#define D 100
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define LSHIFT 65505
#define LALT 65513

// INCLUDE

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>
# include <X11/X.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

// ERROR

#define ERR_ARGS "	incorrect arguments number"
#define ERR_FORMAT "	incorrect file format"
#define ERR_OPEN "	failed to open path"
#define ERR_EMPTY_OR_FOLDER "	path points to empty file or folder"
#define ERR_WALL_REPEAT "	wall is repeated in scene description file"
#define ERR_FC_REPEAT "	floor or ceiling is repeated \
in scene description file"
#define ERR_FC_MISS "	floor or ceiling is missing in scene description file"
#define ERR_WALL_MISS "	wall is missing in scene description file"
#define ERR_FC_FORMAT "	color format invalid"
#define ERR_FC_BOUNDS "	color value out of bounds"
#define ERR_NEWLINE_MAP "	empty line in map"
#define ERR_OPEN_MAP "	open map"
#define ERR_NO_MAP "	missing map"
#define ERR_PATH_WALL "	wall path incorrect"
#define ERR_SPACE_END_PATH "	trim chars at end of wall path"
#define ERR_SPAWN "	map needs exactly ONE of the following chars: N S W E"
#define BAD_CHAR "	invalid character"
#define ERR_CHAR_FILE "	invalid character in scene description file"
#define MALLOC "	malloc failure"
#define ERR_ENVP " missing env variable(s)"
#define ERR_ONLINE "online setup failed"
#define ERR_IP_FORMAT "wrong IP format"
#define ERR_MALLOC "malloc failure"


typedef	enum e_side
{
	NO = 0,
	EA = 1,
	SO = 2,
	WE = 3,
} t_side;


typedef struct s_vect
{
	double	x;
	double	y;
} t_vect;

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
		// t_tile	step;
}	t_ray;

typedef struct s_player
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
	
}	t_player;

typedef	struct s_map
{
	char **map_skeleton;
	char	*NO_text_path;
	char	*SO_text_path;
	char	*EA_text_path;
	char	*WE_text_path;
	int		floor_rgb[3];
	int		floor_hex;
	int		ceiling_rgb[3];
	int		ceiling_hex;
	int		map_width;
	int		map_height;
	t_player	*player;
	
}	t_map;

typedef	struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*mlx_img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	t_map	*map;
	
}	t_game;

int		close_display(t_game *game);

// init.c
t_game	*init_game(void);

// events.c
void	handle_events(t_game *game);
int		on_keypress(int keycode, t_game *game);

void	render_frame(t_game *game);

t_map	*hardcoded_map();

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
double	DDA_loop(t_map map, t_ray *ray);
void	render_frame(t_game *game);
void	putpixel(t_game game, int x, int y, int color);

#endif