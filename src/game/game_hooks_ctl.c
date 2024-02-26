/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_ctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:29:57 by javigarc          #+#    #+#             */
/*   Updated: 2022/11/30 15:56:57 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_key_press(int key, t_gamedata *gdata)
{
	if (key == 53)
	{
		//ft_free_map(gdata);
		ft_putstr_fd("\r\nTerminating.\nOK.", 1);
		close_game(gdata);
		exit(0);
	}/*
	if (key == 69 || key == 24 || key == 78 || key == 27)
		ft_scale(key, gdata);
	else if (key == 123 || key == 124
		|| key == 125 || key == 126)
		ft_axis_displ(key, gdata);
	else if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		ft_rotate_view(key, gdata);
	else if (key == 6 || key == 7)
		ft_change_height(key, gdata);
	else if (key == 35)
		ft_change_view(key, gdata);*/
	return (0);
}

int	ft_button_close(t_gamedata *gdata)
{
	//ft_free_map(gdata);
	ft_putstr_fd("\rProgram terminated successfully", 1);
	close_game(gdata);
	exit (0);
}
