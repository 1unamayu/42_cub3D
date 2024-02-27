/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/27 13:56:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b);
void	ft_light_rect(t_gamedata *gdata, t_coord begin, t_coord end, int color);
void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color);

void	ft_start_draw(t_gamedata *gdata)
{
	t_coord start;
	t_coord end;

    (void)start;
	start.x = 0;
	start.y = 0;
	end.x = gdata->img_size.x;
	end.y = gdata->img_size.y / 2;
	ft_clear_image(gdata, BKG_CLR_A, BKG_CLR_B);
	ft_light_rect(gdata, start, end, ft_to_color_argb(gdata->map->c_celing));
	start.y = end.y;
	end.y = gdata->img_size.y;
	ft_putstr_fd("\ndibujando elsuelo ahora..", 1);
	ft_light_rect(gdata, start, end, ft_to_color_argb(gdata->map->c_floor));
	ft_raycasting(gdata);
	//ft_start_line_row(gdata);
	//ft_start_line_col(gdata);
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 0, 0);
}

void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < gdata->win_size.x)
	{
		y = 0;
		while (y < gdata->win_size.y)
		{
			if (y % 2)
				ft_light_my_pixel(gdata, x, y, color_a);
			else
				ft_light_my_pixel(gdata, x, y, color_b);
			++y;
		}
		++x;
	}
}

void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color)
{
	int	lpixel;
	int	width;
	int	height;

	width = gdata->img_size.x;
	height = gdata->img_size.y;
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * gdata->pixel_b / 8) + (y * gdata->lines_b);
		gdata->imgadd[lpixel] = color;
		gdata->imgadd[++lpixel] = color >> 8;
		gdata->imgadd[++lpixel] = color >> 16;
	}
}

void	ft_light_rect(t_gamedata *gdata, t_coord begin, t_coord end, int color)
{
	double	i;
	double	j;

	ft_putnbr_fd(color,1);
	i = begin.x;
	while (i <= end.x)
	{
		j = begin.y;
		while (j <= end.y)
		{
			ft_light_my_pixel(gdata, i, j, color);
			j++;
		}
		i++;
	}
}
void	ft_draw_ray_wall(t_gamedata *gdata, t_raysdt *ray, int color)
{
	int	i;
	ray-> start = gdata->img_size.y / 2 - ray->wallheight / 2;
	ray-> end = gdata->img_size.y / 2 + ray->wallheight / 2;
	ft_putnbr_fd(color,1);
	if (ray->side == 1)
		color = color / 2;
	i = ray->start;
		while (i <= ray->end)
		{
			ft_light_my_pixel(gdata, ray->pix, i, color);
			i++;
		}
}
