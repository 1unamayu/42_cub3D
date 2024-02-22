/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:28:03 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:28:14 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_coord	ft_cal_pro(t_gamedata *gdata, int x, int y, int z)
{
	t_coord	coord;
	int		scale;

	scale = gdata->hookmods.scale;
	coord.color = ft_dot_color(ft_percent(gdata->min_hz, gdata->max_hz, z));
	x *= scale;
	y *= scale;
	z *= scale / gdata->hookmods.z_height;
	ft_rotate_x_axis(&y, &z, gdata->hookmods.x_angle);
	ft_rotate_y_axis(&x, &z, gdata->hookmods.y_angle);
	ft_rotate_z_axis(&x, &y, gdata->hookmods.z_angle);
	if (gdata->hookmods.view != 0)
		gdata->hookmods.angle = 30;
	else
		gdata->hookmods.angle = 15;
	coord.rowx = (x - y) * -cos(rad(gdata->hookmods.angle));
	coord.coly = -z + (x + y) * sin(rad(gdata->hookmods.angle));
	coord.rowx += (gdata->img_size.rowx / 2) + gdata->hookmods.xdispl;
	coord.coly += ((gdata->img_size.coly - gdata->map.rowscols.coly) / 2)
		+ gdata->hookmods.ydispl;
	return (coord);
}

double	rad(int deg)
{
	return (deg * 3.14159265F / 180.0F);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-(x));
	else
		return ((x));
}
