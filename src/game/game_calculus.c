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

t_coord	ft_cal_pro(t_fdfdata *fdata, int x, int y, int z)
{
	t_coord	coord;
	int		scale;

	scale = fdata->hookmods.scale;
	coord.color = ft_dot_color(ft_percent(fdata->min_hz, fdata->max_hz, z));
	x *= scale;
	y *= scale;
	z *= scale / fdata->hookmods.z_height;
	ft_rotate_x_axis(&y, &z, fdata->hookmods.x_angle);
	ft_rotate_y_axis(&x, &z, fdata->hookmods.y_angle);
	ft_rotate_z_axis(&x, &y, fdata->hookmods.z_angle);
	if (fdata->hookmods.view != 0)
		fdata->hookmods.angle = 30;
	else
		fdata->hookmods.angle = 15;
	coord.rowx = (x - y) * -cos(rad(fdata->hookmods.angle));
	coord.coly = -z + (x + y) * sin(rad(fdata->hookmods.angle));
	coord.rowx += (fdata->img_size.rowx / 2) + fdata->hookmods.xdispl;
	coord.coly += ((fdata->img_size.coly - fdata->map.rowscols.coly) / 2)
		+ fdata->hookmods.ydispl;
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
