/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:53:36 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/26 19:54:00 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "game.h"

void	ft_show_menu(t_gamedata *gdata, char *line)
{
	mlx_string_put(gdata->mlx, gdata->win, 10, 15, TXT_CLR_A, " MAP: ");
	mlx_string_put(gdata->mlx, gdata->win, 65, 15, BKG_CLR_A, line);
	line = "------------------------------";
	mlx_string_put(gdata->mlx, gdata->win, 10, 30, P00_CLR, line);
	line = "    Forward: W | Key UP";
	mlx_string_put(gdata->mlx, gdata->win, 15, 50, P30_CLR, line);
	line = "  Backwards: S | Key DOWN";
	mlx_string_put(gdata->mlx, gdata->win, 15, 70, P30_CLR, line);
	line = "      Right: D";
	mlx_string_put(gdata->mlx, gdata->win, 15, 90, P30_CLR, line);
	line = "       Left: A";
	mlx_string_put(gdata->mlx, gdata->win, 15, 110, P30_CLR, line);
	line = "Rotate Right: Key RIGHT";
	mlx_string_put(gdata->mlx, gdata->win, 15, 130, P50_CLR, line);
	line = " Rotate Left: Key LEFT";
	mlx_string_put(gdata->mlx, gdata->win, 15, 150, P50_CLR, line);
	line = "      Action: SPACE";
	mlx_string_put(gdata->mlx, gdata->win, 15, 170, P70_CLR, line);
	line = "";
	mlx_string_put(gdata->mlx, gdata->win, 15, 190, P80_CLR, line);
	line = "   Terminate: ESC";
	mlx_string_put(gdata->mlx, gdata->win, 15, 215, P90_CLR, line);
}