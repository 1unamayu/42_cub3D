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

void	ft_light_my_pixel(t_fdfdata *fdata, int x, int y, int color)
{
	int	lpixel;
	int	width;
	int	height;

	width = fdata->img_size.rowx;
	height = fdata->img_size.coly;
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * fdata->pixel_b / 8) + (y * fdata->lines_b);
		fdata->imgadd[lpixel] = color;
		fdata->imgadd[++lpixel] = color >> 8;
		fdata->imgadd[++lpixel] = color >> 16;
	}
}

void	ft_draw_menu(t_fdfdata *fdata, char *line)
{
	mlx_string_put(fdata->mlx, fdata->win, 10, 15, TXT_CLR_A, " MAP: ");
	mlx_string_put(fdata->mlx, fdata->win, 65, 15, TXT_CLR_B, line);
	line = "------------------------------";
	mlx_string_put(fdata->mlx, fdata->win, 10, 30, DEF_CLR, line);
	line = "Move Axis X,Y: Arrow Keys";
	mlx_string_put(fdata->mlx, fdata->win, 15, 50, TXT_CLR_A, line);
	line = "Zoom: + | -";
	mlx_string_put(fdata->mlx, fdata->win, 15, 70, TXT_CLR_A, line);
	line = "Perspective: P";
	mlx_string_put(fdata->mlx, fdata->win, 15, 90, TXT_CLR_A, line);
	line = "Rotation";
	mlx_string_put(fdata->mlx, fdata->win, 15, 110, TXT_CLR_A, line);
	line = "       X Axis: Q | A";
	mlx_string_put(fdata->mlx, fdata->win, 15, 125, TXT_CLR_A, line);
	line = "       Y Axis: W | S";
	mlx_string_put(fdata->mlx, fdata->win, 15, 140, TXT_CLR_A, line);
	line = "       Z Axis: E | D";
	mlx_string_put(fdata->mlx, fdata->win, 15, 155, TXT_CLR_A, line);
	line = "Height: Z | X";
	mlx_string_put(fdata->mlx, fdata->win, 15, 175, TXT_CLR_A, line);
	line = "Terminate: ESC";
	mlx_string_put(fdata->mlx, fdata->win, 15, 195, TXT_CLR_A, line);
}

void	ft_clear_image(t_fdfdata *fdata, int color_a, int color_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < fdata->win_size.rowx)
	{
		y = 0;
		while (y < fdata->win_size.coly)
		{
			if (y % 2)
				ft_light_my_pixel(fdata, x, y, color_a);
			else
				ft_light_my_pixel(fdata, x, y, color_b);
			++y;
		}
		++x;
	}
}

void	ft_light_line(t_fdfdata *fdata, t_coord begin, t_coord end, t_bnum num)
{
	while ((num.cur.rowx != end.rowx) || (num.cur.coly != end.coly))
	{
		ft_light_my_pixel(fdata, num.cur.rowx, num.cur.coly, \
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

void	ft_draw_scale(t_fdfdata *fdata)
{
	char	*line;
	int		x;

	x = 95;
	mlx_string_put(fdata->mlx, fdata->win, (x - 7), 400, TXT_CLR_B, \
			"COLOR SCALE");
	line = "      ---------------";
	mlx_string_put(fdata->mlx, fdata->win, 10, 410, DEF_CLR, line);
	mlx_string_put(fdata->mlx, fdata->win, x, 425, P00_CLR, "90 - 100 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 445, P90_CLR, "80 - 90 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 465, P80_CLR, "70 - 80 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 485, P70_CLR, "60 - 70 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 505, P60_CLR, "50 - 60 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 525, P50_CLR, "40 - 50 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 545, P40_CLR, "30 - 40 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 565, P30_CLR, "20 - 30 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 585, P20_CLR, "10 - 20 \%");
	mlx_string_put(fdata->mlx, fdata->win, x, 605, P10_CLR, " 0 - 10 \%");
}
