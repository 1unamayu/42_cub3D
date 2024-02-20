/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:03 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/20 18:39:05 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_main(int argc)
{
	t_fdfdata	fdata;

	char	*map;

	map = "src/game/mars.fdf";

	if (argc == 2)
	{
		ft_putstr_fd("\rChecking file...", 1);
		fdata.map = ft_read_map(map);
		ft_putstr_fd("\rReading map...", 1);
		fdata.map_name = map;
		ft_putstr_fd("\rIniciating...", 1);
		ft_fdfdata_init(&fdata);
		ft_hookmods_init(&fdata);
		ft_start_hooks(&fdata);
		ft_putstr_fd("\rCalculating...", 1);
		ft_start_draw(&fdata);
		ft_draw_menu(&fdata, map);
		ft_draw_scale(&fdata);
		ft_putstr_fd("\r\nDone!", 1);
		mlx_loop(fdata.mlx);
	}
	else
		ft_putstr_fd("madre mia\n", 1);
	return (0);
}

void	ft_fdfdata_init(t_fdfdata *fdata)
{
	fdata->mlx = mlx_init();
	fdata->win_size.rowx = 1920;
	fdata->win_size.coly = 1080;
	fdata->img_size.rowx = 1600;
	fdata->img_size.coly = 1080;
	fdata->win = mlx_new_window(fdata->mlx, fdata->win_size.rowx, \
			fdata->win_size.coly, "FDF");
	fdata->img = mlx_new_image(fdata->mlx, fdata->img_size.rowx, \
			fdata->img_size.coly);
	fdata->imgadd = mlx_get_data_addr(fdata->img, &fdata->pixel_b, \
			&fdata->lines_b, &fdata->endian);
	ft_set_maxmin_hz(fdata, fdata->map.rowscols.rowx, fdata->map.rowscols.coly);
}

void	ft_hookmods_init(t_fdfdata *fdata)
{
	int	escw;
	int	esch;

	esch = (fdata->img_size.coly / fdata->map.rowscols.coly / 2);
	escw = (fdata->img_size.rowx / fdata->map.rowscols.rowx / 2);
	if (esch < escw)
		fdata->hookmods.scale = esch / 2;
	else
		fdata->hookmods.scale = escw / 2;
	if (fdata->hookmods.scale < 1)
		fdata->hookmods.scale = 2;
	fdata->hookmods.angle = 30;
	fdata->hookmods.xdispl = 0;
	fdata->hookmods.ydispl = 0;
	fdata->hookmods.view = 1;
	fdata->hookmods.x_angle = 0;
	fdata->hookmods.y_angle = 0;
	fdata->hookmods.z_angle = 0;
	fdata->hookmods.z_height = 1;
}

void	ft_set_maxmin_hz(t_fdfdata *fdata, int rows, int cols)
{
	int	x;
	int	y;

	fdata->max_hz = fdata->map.mapdots[0][0].hz;
	fdata->min_hz = fdata->max_hz;
	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (fdata->map.mapdots[x][y].hz > fdata->max_hz)
				fdata->max_hz = fdata->map.mapdots[x][y].hz;
			if (fdata->map.mapdots[x][y].hz < fdata->min_hz)
				fdata->min_hz = fdata->map.mapdots[x][y].hz;
			y++;
		}
		x++;
	}
}

void	ft_free_map(t_fdfdata *fdata)
{
	int	x;

	x = 0;
	while (x < fdata->map.rowscols.rowx)
	{
		free(fdata->map.mapdots[x]);
		x++;
	}
	free(fdata->map.mapdots);
}
