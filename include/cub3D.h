/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:49:50 by elmondo           #+#    #+#             */
/*   Updated: 2026/01/17 16:43:47 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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