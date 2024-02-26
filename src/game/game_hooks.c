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

/*void	ft_scale(int key, t_gamedata *gdata)
{
	if (key == 69 || key == 24 || key == 4)
	{
		gdata->hookmods.scale++;
	}
	else if (key == 78 || key == 27 || key == 5)
		gdata->hookmods.scale--;
	if (gdata->hookmods.scale < 1)
		gdata->hookmods.scale = 1;
	ft_start_draw(gdata);
}
*/
/*void	ft_axis_displ(int key, t_gamedata *gdata)
{
	if (key == 123)
		gdata->hookmods.xdispl -= 10;
	else if (key == 124)
		gdata->hookmods.xdispl += 10;
	else if (key == 125)
		gdata->hookmods.ydispl += 10;
	else
		gdata->hookmods.ydispl -= 10;
	ft_start_draw(gdata);
}

void	ft_rotate_view(int key, t_gamedata *gdata)
{
	if (key == 14)
		gdata->hookmods.z_angle += 0.05;
	if (key == 2)
		gdata->hookmods.z_angle -= 0.05;
	if (key == 12)
		gdata->hookmods.x_angle -= 0.05;
	if (key == 0)
		gdata->hookmods.x_angle += 0.05;
	if (key == 13)
		gdata->hookmods.y_angle += 0.05;
	if (key == 1)
		gdata->hookmods.y_angle -= 0.05;
	ft_start_draw(gdata);
}

void	ft_change_height(int key, t_gamedata *gdata)
{
	if (key == 6)
		gdata->hookmods.z_height -= 0.1;
	else if (key == 7)
		gdata->hookmods.z_height += 0.1;
	if (gdata->hookmods.z_height < 0.1)
		gdata->hookmods.z_height = 0.1;
	else if (gdata->hookmods.z_height > 10)
		gdata->hookmods.z_height = 10;
	ft_start_draw(gdata);
}

void	ft_change_view(int key, t_gamedata *gdata)
{
	if (key == 35)
	{
		gdata->hookmods.x_angle = 0;
		gdata->hookmods.y_angle = 0;
		gdata->hookmods.z_angle = 0;
		if (gdata->hookmods.view)
			gdata->hookmods.view = 0;
		else
			gdata->hookmods.view++;
	}
	ft_start_draw(gdata);
}
*/