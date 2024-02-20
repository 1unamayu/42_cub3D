/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:29:42 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:29:47 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_scale(int key, t_fdfdata *fdata)
{
	if (key == 69 || key == 24 || key == 4)
	{
		fdata->hookmods.scale++;
	}
	else if (key == 78 || key == 27 || key == 5)
		fdata->hookmods.scale--;
	if (fdata->hookmods.scale < 1)
		fdata->hookmods.scale = 1;
	ft_start_draw(fdata);
}

void	ft_axis_displ(int key, t_fdfdata *fdata)
{
	if (key == 123)
		fdata->hookmods.xdispl -= 10;
	else if (key == 124)
		fdata->hookmods.xdispl += 10;
	else if (key == 125)
		fdata->hookmods.ydispl += 10;
	else
		fdata->hookmods.ydispl -= 10;
	ft_start_draw(fdata);
}

void	ft_rotate_view(int key, t_fdfdata *fdata)
{
	if (key == 14)
		fdata->hookmods.z_angle += 0.05;
	if (key == 2)
		fdata->hookmods.z_angle -= 0.05;
	if (key == 12)
		fdata->hookmods.x_angle -= 0.05;
	if (key == 0)
		fdata->hookmods.x_angle += 0.05;
	if (key == 13)
		fdata->hookmods.y_angle += 0.05;
	if (key == 1)
		fdata->hookmods.y_angle -= 0.05;
	ft_start_draw(fdata);
}

void	ft_change_height(int key, t_fdfdata *fdata)
{
	if (key == 6)
		fdata->hookmods.z_height -= 0.1;
	else if (key == 7)
		fdata->hookmods.z_height += 0.1;
	if (fdata->hookmods.z_height < 0.1)
		fdata->hookmods.z_height = 0.1;
	else if (fdata->hookmods.z_height > 10)
		fdata->hookmods.z_height = 10;
	ft_start_draw(fdata);
}

void	ft_change_view(int key, t_fdfdata *fdata)
{
	if (key == 35)
	{
		fdata->hookmods.x_angle = 0;
		fdata->hookmods.y_angle = 0;
		fdata->hookmods.z_angle = 0;
		if (fdata->hookmods.view)
			fdata->hookmods.view = 0;
		else
			fdata->hookmods.view++;
	}
	ft_start_draw(fdata);
}
