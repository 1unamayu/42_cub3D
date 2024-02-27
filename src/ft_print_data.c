/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:16:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 12:59:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_print_map(char **map2d);

/**
 * Prints detailed map and game configuration information.
 * 
 * This function displays on the console the paths to the textures used for
 * the different sides of the map (north, south, east, west), the RGB colors
 * for the floor and ceiling, and finally prints the introduced map.
 * 
 * @param data A t_data structure containing all the map information
 * and game configuration to be printed.
 */
void	ft_print(t_data data)
{
	printf(KCYN"\t Texture NO   : %s", data.t_no.texture_path);
	printf(KCYN"\t Texture SO   : %s", data.t_so.texture_path);
	printf(KCYN"\t Texture WE   : %s", data.t_we.texture_path);
	printf(KCYN"\t Texture EA   : %s", data.t_ea.texture_path);
	printf(KMAG"\t Floor color  : RGB");
	printf("(%d, %d, %d) \n", data.c_floor.r, data.c_floor.g, data.c_floor.b);
	printf(KMAG"\t Ceiling color: RGB");
	printf("(%d, %d, %d)\n\n", data.c_celing.r, data.c_celing.g, \
								data.c_celing.b);
	ft_print_map(data.map2d);
	printf("\n");
}

/**
 * Prints the 2D map to the console.
 * 
 * This function iterates through the provided 2D map and prints it to the console.
 * The '1' characters are printed in cyan to represent walls, the '0' characters
 * are printed in blue to represent empty spaces, and any other character
 * is printed in red, indicating non-mappable or special elements.
 * 
 * @param map2d The 2D map to print.
 */
static void	ft_print_map(char **map2d)
{
	int	cont;
	int	col;
	int	map_lines;

	cont = 0;
	map_lines = ft_2d_array_size(map2d);
	printf("\t ");
	while (cont < map_lines)
	{
		col = 0;
		while (map2d[cont][col] != '\0')
		{
			if (map2d[cont][col] == '1')
				printf(KCYN"%c", map2d[cont][col]);
			else if (map2d[cont][col] == '0')
				printf(KBLU"%c", map2d[cont][col]);
			else
				printf(KRED"%c", map2d[cont][col]);
			col++;
		}
		cont++;
		printf("\t ");
	}
	printf(KNRM"\n");
}
