/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:49:50 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/17 16:21:55 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_ALLOWED "01NSEW \n"

// SCREEN

# define WID	600
# define LEN	400

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

typedef	struct s_game
{
	void	*mlx;
	void	*mlx_win;
}	t_game;

int		close_display(t_game *game);

// init.c
t_game	*init_game(void);

// events.c
void	handle_events(t_game *game);
int		on_keypress(int keycode, t_game *game);

#endif