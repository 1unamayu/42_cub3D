/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:03 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:55:12 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_main(int argc)
{
	t_gamedata	gdata;
	char	*mapita = "src/game/pyramide.fdf";
ft_putstr_fd("\nIN GAME\n\n\n", 1);
	if (argc == 2)
	{
		ft_putstr_fd("\rChecking file...", 1);
		gdata.map = ft_read_map(mapita);
		ft_putstr_fd("\rReading map...", 1);
		gdata.map_name = mapita;
		ft_putstr_fd("\rIniciating...", 1);
		ft_gamedata_init(&gdata);
		ft_hookmods_init(&gdata);
		ft_start_hooks(&gdata);
		ft_putstr_fd("\rCalculating...", 1);
		ft_start_draw(&gdata);
		ft_draw_menu(&gdata, mapita);
		ft_draw_scale(&gdata);
		ft_putstr_fd("\r\nDone!", 1);
		mlx_loop(gdata.mlx);
	}
	else
		ft_putstr_fd("Something went wrong\n", 2);
	return (0);
}

void	ft_gamedata_init(t_gamedata *gdata)
{
	gdata->mlx = mlx_init();
	gdata->win_size.rowx = 1920;
	gdata->win_size.coly = 1080;
	gdata->img_size.rowx = 1600;
	gdata->img_size.coly = 1080;
	gdata->win = mlx_new_window(gdata->mlx, gdata->win_size.rowx, \
			gdata->win_size.coly, "FDF");
	gdata->img = mlx_new_image(gdata->mlx, gdata->img_size.rowx, \
			gdata->img_size.coly);
	gdata->imgadd = mlx_get_data_addr(gdata->img, &gdata->pixel_b, \
			&gdata->lines_b, &gdata->endian);
	ft_set_maxmin_hz(gdata, gdata->map.rowscols.rowx, gdata->map.rowscols.coly);
}

void	ft_hookmods_init(t_gamedata *gdata)
{
	int	escw;
	int	esch;

	esch = (gdata->img_size.coly / gdata->map.rowscols.coly / 2);
	escw = (gdata->img_size.rowx / gdata->map.rowscols.rowx / 2);
	if (esch < escw)
		gdata->hookmods.scale = esch / 2;
	else
		gdata->hookmods.scale = escw / 2;
	if (gdata->hookmods.scale < 1)
		gdata->hookmods.scale = 2;
	gdata->hookmods.angle = 30;
	gdata->hookmods.xdispl = 0;
	gdata->hookmods.ydispl = 0;
	gdata->hookmods.view = 1;
	gdata->hookmods.x_angle = 0;
	gdata->hookmods.y_angle = 0;
	gdata->hookmods.z_angle = 0;
	gdata->hookmods.z_height = 1;
}

void	ft_set_maxmin_hz(t_gamedata *gdata, int rows, int cols)
{
	int	x;
	int	y;

	gdata->max_hz = gdata->map.mapdots[0][0].hz;
	gdata->min_hz = gdata->max_hz;
	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (gdata->map.mapdots[x][y].hz > gdata->max_hz)
				gdata->max_hz = gdata->map.mapdots[x][y].hz;
			if (gdata->map.mapdots[x][y].hz < gdata->min_hz)
				gdata->min_hz = gdata->map.mapdots[x][y].hz;
			y++;
		}
		x++;
	}
}

void	ft_free_map(t_gamedata *gdata)
{
	int	x;

	x = 0;
	while (x < gdata->map.rowscols.rowx)
	{
		free(gdata->map.mapdots[x]);
		x++;
	}
	free(gdata->map.mapdots);
}
