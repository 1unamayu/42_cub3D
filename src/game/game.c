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

int	start_the_game(t_data *valmap, char *level)
{
	t_gamedata	gdata;
	
ft_putstr_fd("\nIN GAME\n\n\n", 1);

		ft_putstr_fd("\rLoading map...", 1);
		gdata.map = valmap;
		gdata.map_name = level;
		ft_putstr_fd("\rLaunching.....", 1);
		ft_gamedata_init(&gdata);
	//	ft_hookmods_init(&gdata);
		ft_start_hooks(&gdata);
		ft_putstr_fd("\rRuning............", 1);
		ft_start_draw(&gdata);
		ft_draw_menu(&gdata, level);
//		ft_draw_scale(&gdata);
//		ft_putstr_fd("\r\nDone!", 1);
		ft_putstr_fd("\n colores:", 1);
		ft_putnbr_fd(gdata.map->c_celing.r,1);
		ft_putchar_fd('-',1);
		ft_putnbr_fd(gdata.map->c_celing.g,1);
		ft_putchar_fd('-',1);
		ft_putnbr_fd(gdata.map->c_celing.b,1);
		ft_putstr_fd("\n floor",1);
		ft_putnbr_fd(gdata.map->c_floor.r,1);
		ft_putchar_fd('-',1);
		ft_putnbr_fd(gdata.map->c_floor.g,1);
		ft_putchar_fd('-',1);
		ft_putnbr_fd(gdata.map->c_floor.b,1);
		//raycasting(&gdata);
		mlx_loop(gdata.mlx);
		close_game(gdata.mlx);
	return (0);
}

void	ft_gamedata_init(t_gamedata *gdata)
{
	//t_dot	maxscreen;

	gdata->mlx = mlx_init();
	//mlx_get_screen_size(gdata->mlx, &maxscreen.x, &maxscreen.y); // comprobar si con otra minilibx que aparezca este prototipo
	/*gdata->win_size.x = maxscreen.x - 100;
	gdata->win_size.y = maxscreen.y - 50;
	gdata->img_size.x = gdata->win_size.x - 100;
	gdata->img_size.y = gdata->win_size.y;
	*/
	init_player(gdata);
	gdata->win_size.x = 1200;
	gdata->win_size.y = 700;
	gdata->img_size.x = gdata->win_size.x;
	gdata->img_size.y = gdata->win_size.y;
	gdata->win = mlx_new_window(gdata->mlx, gdata->win_size.x, \
			gdata->win_size.y, "[*]----:*:-^-[CUB3D]-^-:*:----[*]");
	gdata->img = mlx_new_image(gdata->mlx, gdata->img_size.x, \
			gdata->img_size.y);
	gdata->imgadd = mlx_get_data_addr(gdata->img, &gdata->pixel_b, \
			&gdata->lines_b, &gdata->endian);
	//ft_set_maxmin_hz(gdata, gdata->map->h_map, gdata->map->w_map);
}

/*void	ft_hookmods_init(t_gamedata *gdata)
{
	int	escw;
	int	esch;

	esch = (gdata->img_size.y / gdata->map->w_map / 2);
	escw = (gdata->img_size.x / gdata->map->h_map / 2);
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
*/
/*void	ft_set_maxmin_hz(t_gamedata *gdata, int rows, int cols)
{
	int	x;
	int	y;

	gdata->max_hz = gdata->map->mapdots[0][0].hz;
	gdata->min_hz = gdata->max_hz;
	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (gdata->map->mapdots[x][y].hz > gdata->max_hz)
				gdata->max_hz = gdata->map->mapdots[x][y].hz;
			if (gdata->map->mapdots[x][y].hz < gdata->min_hz)
				gdata->min_hz = gdata->map->mapdots[x][y].hz;
			y++;
		}
		x++;
	}
}
*/
/*void	ft_free_map(t_gamedata *gdata)
{
	int	x;

	x = 0;
	while (x < gdata->map->rowscols.x)
	{
		free(gdata->map->mapdots[x]);
		x++;
	}
	free(gdata->map->mapdots);
}*/
int	close_game(t_gamedata *gdata)
{
	mlx_destroy_image(gdata->mlx, gdata->img);
	mlx_destroy_window(gdata->mlx, gdata->win);
	return (0);
}