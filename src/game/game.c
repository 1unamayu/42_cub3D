/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:03 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/26 19:57:48 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
static void ft_gamedata_init(t_gamedata *gdata);
static void	ft_init_player(t_gamedata *gdata);

int	start_the_game(t_data *valmap, char *level)
{
	t_gamedata	gdata;
	
    ft_putstr_fd("\nIN GAME 2\n\n\n", 1);
    gdata.map = valmap;
	gdata.map_name = level;
    ft_gamedata_init(&gdata);
    ft_start_hooks(&gdata);
    ft_start_draw(&gdata);
    ft_show_menu(&gdata, level);
    mlx_loop(gdata.mlx);
    //close_game();
	return (0);
}

static void ft_gamedata_init(t_gamedata *gdata)
{
    gdata->mlx = mlx_init();
    gdata->win_size.x = W_RESOL;
    gdata->win_size.y = H_RESOL;

    gdata->img_size.x = W_RESOL;
    gdata->img_size.y = H_RESOL;

    ft_init_player(gdata);
    gdata->win = mlx_new_window(gdata->mlx, gdata->win_size.x, \
			gdata->win_size.y, "[*]----:*:-^-[CUB3D]-^-:*:----[*]");
	gdata->img = mlx_new_image(gdata->mlx, gdata->img_size.x, \
			gdata->img_size.y);
	gdata->imgadd = mlx_get_data_addr(gdata->img, &gdata->pixel_b, \
			&gdata->lines_b, &gdata->endian);
}

static void	ft_init_player(t_gamedata *gdata)
{
	char	initdir;

	initdir = gdata->map->map2d[gdata->map->p_x][gdata->map->p_y];
	gdata->player.dir.x = 0;
	gdata->player.dir.y = 0;
	if (ft_strncmp(&initdir, "N", 1) == 0)
		gdata->player.dir.y = -1;
	if (ft_strncmp(&initdir, "E", 1) == 0)
		gdata->player.dir.x = 1;
	if (ft_strncmp(&initdir, "S", 1) == 0)
		gdata->player.dir.y = 1;
	if (ft_strncmp(&initdir, "W", 1) == 0)
		gdata->player.dir.x = -1;
	gdata->player.plane.x = 0.66;
	gdata->player.plane.y = 0;
	gdata->player.pos.x = gdata->map->p_x;
	gdata->player.pos.y = gdata->map->p_y;
}

