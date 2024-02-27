/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:24:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata);
static void ft_print_ray_info(t_raysdt *ray, t_gamedata *gdata, int type);

void	ft_raycasting(t_gamedata *gdata)
{
	t_raysdt	*ray;

	ray = ft_calloc(1, sizeof (t_raysdt));
	
	ray->wallhit = 0;
	while (ray->pix < gdata->win_size.x)
	{
		ft_ray_init(ray, gdata);
		if (ray->dir.x < 0)
		{
			ray->step.x = -1;
			ray->sidedist.x = (gdata->player.pos.x - ray->map.x) * ray->delta.x;
		}
		else
		{
			ray->step.x = 1;
			ray->sidedist.x = (ray->map.x + 1.0 - gdata->player.pos.x) * ray->delta.x;
		}
		if (ray->dir.y < 0)
		{
			ray->step.y = -1;
			ray->sidedist.y = (gdata->player.pos.y - ray->map.y) * ray->delta.y;
		}
		else
		{
			ray->step.y = 1;
			ray->sidedist.y = (ray->map.y + 1.0 - gdata->player.pos.y) * ray->delta.y;
		}
		while (ray->wallhit == 0)
		{
			if (ray->sidedist.x < ray->sidedist.y)
			{
				ray->sidedist.x += ray->delta.x;
				ray->map.x += ray->step.x;
				ray->side = 0;
			}
			else
			{
				ray->sidedist.y += ray->delta.y;
				ray->map.y += ray->step.y;
				ray->side = 1;
			}
			if (gdata->map->map2d[ray->map.x][ray->map.y] == '1')
			{
				printf("\n %c - ", gdata->map->map2d[ray->map.x][ray->map.y]);
				ray->wallhit = 1;
				ft_print_ray_info(ray, gdata,1);
			}
			if (ray->side == 0)
				ray->walldist = ray->sidedist.x - ray->delta.x;
			else
				ray->walldist = ray->sidedist.y - ray->delta.y;
		}
		if (ray->walldist == 0)
			ray->wallheight = 690;
		else
			ray->wallheight = 700 / ray->walldist;
		printf("  wallheight: %f \n", ray->wallheight);
		t_color colorin;

		colorin.r= 255;
		colorin.g = 0;
		colorin.b = 0;
		ft_draw_ray_wall(gdata, ray, ft_to_color_argb(colorin));
		ray->pix++;
	}
}

static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata)
{
	ray->camerax = (2 * ray->pix) / (double)gdata->win_size.x - 1;
	//cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents, done this way so that the right side of the screen will get coordinate 1, the center of the screen gets coordinate 0, and the left side of the screen gets coordinate -1. Out of this, the direction of the ray can be calculated as was explained earlier: as the sum of the direction vector, and a part of the plane vector. This has to be done both for the x and y coordinate of the vector (since adding two vectors is adding their x-coordinates, and adding their y-coordinates).
	ray->dir.x = (gdata->player.dir.x + gdata->player.plane.x * ray->camerax);
	ray->dir.y = gdata->player.dir.y + gdata->player.plane.y * ray->camerax;
	
	ray->map.x = (int)gdata->player.pos.x;
	ray->map.y = (int)gdata->player.pos.y;
	
	if (ray->dir.x == 0)
		ray->delta.x = 1E30;
	else
		ray->delta.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta.y = 1E30;
	else
		ray->delta.y = fabs(1 / ray->dir.y);
	ray->wallhit = 0;
	
}
static void ft_print_ray_info(t_raysdt *ray, t_gamedata *gdata, int type)
{
	if (type == 0)
	{
		printf("\nray pix %d", ray->pix);
		printf("\nplayer plane x %f", gdata->player.plane.x);
		printf("\nplayer plane y %f", gdata->player.plane.y);

		printf("\ncamerax: %f\n", ray->camerax);
		printf("dir.x: %f, dir.y: %f\n", ray->dir.x, ray->dir.y);
		printf("map.x: %d, map.y: %d\n", ray->map.x, ray->map.y);
		printf("delta.x: %f, delta.y: %f\n", ray->delta.x, ray->delta.y);
		printf("wallhit: %d\n", ray->wallhit);
	}
	if (type == 1)
	{
		printf("map.x: %d, map.y: %d", ray->map.x, ray->map.y);
		printf(" X= %d", ray->pix);
	}
	
}