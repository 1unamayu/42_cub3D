/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/22 17:38:14 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define DEF_CLR 0xE2E270
# define P10_CLR 0x1915FF
# define P20_CLR 0x6D00AF
# define P30_CLR 0xCB00BF
# define P40_CLR 0xFF066A
# define P50_CLR 0xFF671D
# define P60_CLR 0xFCFF6D
# define P70_CLR 0xAEFF95
# define P80_CLR 0x98FFE6
# define P90_CLR 0xB3E6FF
# define P00_CLR 0xFDFDFD
# define BKG_CLR_A 0x151515
# define BKG_CLR_B 0x303030
# define TXT_CLR_A 0xF7F7DA
# define TXT_CLR_B 0xAC0FAC

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "game_struct.h"
# include "../src/minilibx/mlx.h"

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4	// player speed

typedef struct s_coord
{
	int	rowx;
	int	coly;
	int	color;
}			t_coord;
typedef struct s_dot
{
	int	hz;
	int	dotcolor;
}			t_dot;
typedef struct s_map
{
	t_dot	**mapdots;
	t_coord	rowscols;
}			t_map;
typedef struct s_maplines
{
	char	**lines;
	char	*line;
	int		x;
	int		y;
	t_dot	**dotstoload;
}			t_maplines;
typedef struct s_bnum
{
	t_coord	delta;
	t_coord	sign;
	t_coord	cur;
	int		error[2];
}			t_bnum;
typedef struct s_mods
{
	int		angle;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		scale;
	int		xdispl;
	int		ydispl;
	int		view;
	float	z_height;
}			t_mods;

typedef struct	s_gamecoord
{	
	double	x;
	double	y;
}				t_gamecoord;

typedef struct	s_gamestate
{
	t_gamecoord	pos; 
	t_gamecoord	dir;
	t_gamecoord	camplane; 
	double		time;    
    double		oldtime;
}				t_gamestate;

typedef struct	s_raysdt
{
	t_gamecoord ray;
  t_gamecoord map;
  t_gamecoord raylento; ////length of ray from current position to next x or y-side
  t_gamecoord raylenfromto; /// //length of ray from one x or y-side to next x or y-side
  t_gamecoord step;
  int         wallhit;
  int         side;
  double      camerax;
  double      perpWallDist;
	/* data */
}				t_raysdt;

typedef struct s_gamedata
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgadd;
	int		pixel_b;
	int		lines_b;
	int		endian;
	char	*map_name;
	t_data	map;
	t_mods	hookmods;
	t_coord	win_size;
	t_coord	img_size;
	t_gamestate	level;
	int		max_hz;
	int		min_hz;
}			t_gamedata;

/// game.c///
int		game_main(int argc);
//t_data *init_argumet();
/// game_init.c///
void	ft_gamedata_init(t_gamedata *gdata);
void	ft_hookmods_init(t_gamedata *gdata);
void	ft_set_maxmin_hz(t_gamedata *gdata, int rows, int cols);
void	ft_free_map(t_gamedata *gdata);
// Map //
t_map	ft_read_map(char *namefile);
t_dot	**ft_load_mapdots(int fd, int rows, int cols);
int		ft_countcols(const char *str, char c);
t_coord	ft_rows_cols_check(int fd);
void	ft_print_map(t_map maptoprint, int rows, int cols);
// Hooks //
void	ft_rotate_view(int key, t_gamedata *gdata);
void	ft_scale(int key, t_gamedata *gdata);
void	ft_axis_displ(int key, t_gamedata *gdata);
void	ft_change_view(int key, t_gamedata *gdata);
void	ft_change_height(int key, t_gamedata *gdata);
// Hooks Control //
int		ft_key_press(int key, t_gamedata *gdata);
int		ft_button_close(t_gamedata *gdata);
// Calculus //
double	rad(int deg);
t_coord	ft_cal_pro(t_gamedata *gdata, int x, int y, int z);
void	ft_swap(int *a, int *b);
int		ft_abs(int x);
// Draw //
void	ft_start_hooks(t_gamedata *gdata);
void	ft_start_draw(t_gamedata *gdata);
void	ft_start_line_row(t_gamedata *gdata);
void	ft_start_line_col(t_gamedata *gdata);
void	ft_draw_line(t_gamedata *gdata, t_coord begin, t_coord end);
// Draw light //
void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color);
void	ft_draw_menu(t_gamedata *gdata, char *line);
void	ft_draw_scale(t_gamedata *gdata);
void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b);
void	ft_light_line(t_gamedata *gdata, t_coord begin, \
		t_coord end, t_bnum bnum);
// Rotations //
void	ft_rotate_x_axis(int *y, int *z, double x_angle);
void	ft_rotate_y_axis(int *x, int *z, double y_angle);
void	ft_rotate_z_axis(int *x, int *y, double z_angle);
// Color //
double	ft_percent(int start, int end, int current);
int		ft_get_light(int start, int end, double percentage);
int		ft_get_color(t_coord cur, t_coord beg, t_coord end, t_coord del);
int		ft_dot_color(double percentage);
#endif
