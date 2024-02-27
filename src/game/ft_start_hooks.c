/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:47 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/26 19:52:14 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_key_press(int key, t_gamedata *gdata);
int	ft_button_close(t_gamedata *gdata);

void	ft_start_hooks(t_gamedata *gdata)
{
	mlx_hook(gdata->win, 2, 0, ft_key_press, gdata);
	mlx_hook(gdata->win, 17, 0, ft_button_close, gdata);
}

int	ft_key_press(int key, t_gamedata *gdata)
{
	(void)gdata;
	printf("\n %d", key);
	if (key == 53) // Tecla ESC para salir
	{
		ft_putstr_fd("\r\nTerminando.\nOK.", 1);
		exit(0);
	}
	else if (key == 0) // Tecla A - Mover izquierda
	{
		ft_putstr_fd("Moviendo a la izquierda.\n", 1);
	}
	else if (key == 2) // Tecla D - Mover derecha
	{
		ft_putstr_fd("Moviendo a la derecha.\n", 1);
	}
	else if (key == 13) // Tecla W - Mover adelante
	{
		ft_putstr_fd("Moviendo adelante.\n", 1);
	}
	else if (key == 1) // Tecla S - Mover atrás
	{
		ft_putstr_fd("Moviendo atrás.\n", 1);
	}
	
	return (0);
}

int	ft_button_close(t_gamedata *gdata)
{
	(void)gdata;
	//ft_free_map(gdata);
	ft_putstr_fd("\rProgram terminated successfully", 1);
	//close_game(gdata);
	exit (0);
}