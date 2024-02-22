/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:28:52 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:28:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_start_hooks(t_gamedata *gdata)
{
	mlx_hook(gdata->win, 2, 0, ft_key_press, gdata);
	mlx_hook(gdata->win, 17, 0, ft_button_close, gdata);
}

void	ft_start_draw(t_gamedata *gdata)
{
	ft_clear_image(gdata, BKG_CLR_A, BKG_CLR_B);
	ft_start_line_row(gdata);
	ft_start_line_col(gdata);
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 320, 0);
}

void	ft_start_line_row(t_gamedata *gdata)
{
	t_coord	begin;
	t_coord	end;
	int		rows;
	int		cols;

	rows = 0;
	while (rows < gdata->map.rowscols.rowx)
	{
		cols = 0;
		while (cols < (gdata->map.rowscols.coly -1))
		{
			begin = ft_cal_pro(gdata, rows, cols,
					gdata->map.mapdots[rows][cols].hz);
			end = ft_cal_pro(gdata, rows, cols + 1,
					gdata->map.mapdots[rows][cols + 1].hz);
			ft_draw_line(gdata, begin, end);
			cols++;
		}
		rows++;
	}
}

void	ft_start_line_col(t_gamedata *gdata)
{
	t_coord	begin;
	t_coord	end;
	int		rows;
	int		cols;

	cols = 0;
	while (cols < gdata->map.rowscols.coly)
	{
		rows = 0;
		while (rows < (gdata->map.rowscols.rowx - 1))
		{
			begin = ft_cal_pro(gdata, rows, cols,
					gdata->map.mapdots[rows][cols].hz);
			end = ft_cal_pro(gdata, rows + 1, cols,
					gdata->map.mapdots[rows + 1][cols].hz);
			ft_draw_line(gdata, end, begin);
			rows++;
		}
		cols++;
	}
}

void	ft_draw_line(t_gamedata *gdata, t_coord begin, t_coord end)
{
	t_bnum	num;

	num.delta.rowx = ft_abs(end.rowx - begin.rowx);
	num.delta.coly = ft_abs(end.coly - begin.coly);
	num.sign.rowx = -1;
	if (begin.rowx < end.rowx)
		num.sign.rowx = 1;
	num.sign.coly = -1;
	if (begin.coly < end.coly)
		num.sign.coly = 1;
	num.error[0] = num.delta.rowx - num.delta.coly;
	num.cur = begin;
	ft_light_line(gdata, begin, end, num);
}
