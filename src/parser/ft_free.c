/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:47:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

/**
 * Frees all allocated memory associated with a t_data structure.
 *
 * This function safely deallocates memory for a t_data structure, including
 * freeing each string in the map2d array and the texture paths for north,
 * south, west, and east directions. It checks for NULL pointers before
 * attempting to free to prevent errors.
 *
 * @param data Pointer to the t_data structure to be freed. If NULL, the
 *             function does nothing.
 */
void	ft_free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->map2d)
	{
		i = 0;
		while (data->map2d[i])
		{
			free(data->map2d[i]);
			i++;
		}
		free(data->map2d);
	}
	free(data->t_no.texture_path);
	free(data->t_so.texture_path);
	free(data->t_we.texture_path);
	free(data->t_ea.texture_path);
	free(data);
}
