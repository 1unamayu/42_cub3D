/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:29:08 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:29:19 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color)
{
	int	lpixel;
	int	width;
	int	height;

	width = gdata->img_size.x;
	height = gdata->img_size.y;
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * gdata->pixel_b / 8) + (y * gdata->lines_b);
		gdata->imgadd[lpixel] = color;
		gdata->imgadd[++lpixel] = color >> 8;
		gdata->imgadd[++lpixel] = color >> 16;
	}
}

void	ft_draw_menu(t_gamedata *gdata, char *line)
{
	mlx_string_put(gdata->mlx, gdata->win, 10, 15, TXT_CLR_A, " MAP: ");
	mlx_string_put(gdata->mlx, gdata->win, 65, 15, BKG_CLR_A, line);
	line = "------------------------------";
	mlx_string_put(gdata->mlx, gdata->win, 10, 30, P00_CLR, line);
	line = "    Forward: W | Key UP";
	mlx_string_put(gdata->mlx, gdata->win, 15, 50, P30_CLR, line);
	line = "  Backwards: S | Key DOWN";
	mlx_string_put(gdata->mlx, gdata->win, 15, 70, P30_CLR, line);
	line = "      Right: D";
	mlx_string_put(gdata->mlx, gdata->win, 15, 90, P30_CLR, line);
	line = "       Left: A";
	mlx_string_put(gdata->mlx, gdata->win, 15, 110, P30_CLR, line);
	line = "Rotate Right: Key RIGHT";
	mlx_string_put(gdata->mlx, gdata->win, 15, 130, P50_CLR, line);
	line = " Rotate Left: Key LEFT";
	mlx_string_put(gdata->mlx, gdata->win, 15, 150, P50_CLR, line);
	line = "      Action: SPACE";
	mlx_string_put(gdata->mlx, gdata->win, 15, 170, P70_CLR, line);
	line = "";
	mlx_string_put(gdata->mlx, gdata->win, 15, 190, P80_CLR, line);
	line = "   Terminate: ESC";
	mlx_string_put(gdata->mlx, gdata->win, 15, 215, P90_CLR, line);
}

int cc_argb(t_color color)
 {
    int colorARGB;
    colorARGB = (0xFF << 24) | (color.r << 16) | (color.g << 8) | color.b;
    return colorARGB;
}

void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < gdata->win_size.x)
	{
		y = 0;
		while (y < gdata->win_size.y)
		{
			if (y % 2)
				ft_light_my_pixel(gdata, x, y, color_a);
			else
				ft_light_my_pixel(gdata, x, y, color_b);
			++y;
		}
		++x;
	}
}


void	ft_light_rect(t_gamedata *gdata, t_coord begin, t_coord end, int color)
{
	double	i;
	double	j;

	ft_putnbr_fd(color,1);
	i = begin.x;
	while (i <= end.x)
	{
		j = begin.y;
		while (j <= end.y)
		{
			ft_light_my_pixel(gdata, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_light_rayline(t_gamedata *gdata, t_raysdt *ray, int color)
{
	int	i;

	ft_putnbr_fd(color,1);
	i = ray->start;
		while (i <= ray->end)
		{
			ft_light_my_pixel(gdata, ray->pix, i, color);
			i++;
		}
}
/*
void	ft_light_line(t_gamedata *gdata, t_coord begin, t_coord end, t_bnum num)
{
	while ((num.cur.rowx != end.rowx) || (num.cur.coly != end.coly))
	{
		ft_light_my_pixel(gdata, num.cur.rowx, num.cur.coly, \
				ft_get_color(num.cur, begin, end, num.delta));
		num.error[1] = num.error[0] * 2;
		if (num.error[1] > -(num.delta.coly))
		{
			num.error[0] -= num.delta.coly;
			num.cur.rowx += num.sign.rowx;
		}
		if (num.error[1] < num.delta.rowx)
		{
			num.error[0] += num.delta.rowx;
			num.cur.coly += num.sign.coly;
		}
	}
}
*/
/*
void	ft_draw_scale(t_gamedata *gdata)
{
	char	*line;
	int		x;

	x = 95;
	mlx_string_put(gdata->mlx, gdata->win, (x - 7), 400, TXT_CLR_B, \
			"COLOR SCALE");
	line = "      ---------------";
	mlx_string_put(gdata->mlx, gdata->win, 10, 410, DEF_CLR, line);
	mlx_string_put(gdata->mlx, gdata->win, x, 425, P00_CLR, "90 - 100 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 445, P90_CLR, "80 - 90 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 465, P80_CLR, "70 - 80 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 485, P70_CLR, "60 - 70 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 505, P60_CLR, "50 - 60 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 525, P50_CLR, "40 - 50 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 545, P40_CLR, "30 - 40 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 565, P30_CLR, "20 - 30 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 585, P20_CLR, "10 - 20 \%");
	mlx_string_put(gdata->mlx, gdata->win, x, 605, P10_CLR, " 0 - 10 \%");
}
*/