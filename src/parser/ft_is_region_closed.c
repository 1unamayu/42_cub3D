/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_region_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:36:48 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:54:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	ft_isborder(int x, int y, int rows, int cols);
static bool	ft_floodfillutil(char **pantalla, int x, int y, bool *isClosed);
static char	**ft_copy_map_data(t_data data, int rows);
static void	ft_free_pantalla(char **pantalla, int rows);

/**
 * Determines if a map region is fully enclosed.
 *
 * This function checks if the region around the player's starting position
 * is completely closed off by walls. It uses a flood fill algorithm starting
 * from the player's position to test if there's any path that leads outside
 * the map boundaries.
 *
 * @param data The game data structure containing the map and player position.
 * @param filename The name of the file containing the map data.
 * @return Returns true if the region is closed, false otherwise.
 */
bool	ft_is_region_closed(t_data data, char *filename)
{
	bool	isclosed;
	int		rows;
	char	**pantalla;

	isclosed = true;
	rows = ft_count_map_lines(filename);
	pantalla = ft_copy_map_data(data, rows);
	pantalla[data.p_x][data.p_y] = '0';
	ft_floodfillutil(pantalla, data.p_x, data.p_y, &isclosed);
	if (!isclosed)
		ft_print_pantalla(pantalla, rows);
	ft_free_pantalla(pantalla, rows);
	return (isclosed);
}

/**
 * Checks if a given position is on the border of the map.
 *
 * This function determines if the coordinates (x, y) are located on the
 * edge of the map, considering the map's dimensions.
 *
 * @param x The x-coordinate to check.
 * @param y The y-coordinate to check.
 * @param rows The total number of rows in the map.
 * @param cols The total number of columns in the map.
 * @return Returns true if the position is on the border, false otherwise.
 */
static bool	ft_isborder(int x, int y, int rows, int cols)
{
	return (x == 0 || x == (rows - 1) || y == 0 || y == (cols - 2));
}

/**
 * Utility function for the flood fill algorithm.
 *
 * Recursively explores the map from a given position to determine if the
 * region is closed. It marks visited positions and checks for openings.
 *
 * @param pantalla The map represented as a 2D array of characters.
 * @param x The current x-coordinate in the map.
 * @param y The current y-coordinate in the map.
 * @param isclosed Pointer to a boolean that indicates if the region is closed.
 * @return Returns true if the current path is valid, false if it leads outside.
 */
static bool	ft_floodfillutil(char **pantalla, int x, int y, bool *isclosed)
{
	int	rows;

	rows = ft_2d_array_size(pantalla);
	if (x < 0 || x > (rows - 1))
		return (false);
	if (y < 0)
		return (false);
	if (y > (int)ft_strlen(pantalla[x]) - 1)
		*isclosed = false;
	if (pantalla[x][y] == 'H')
		*isclosed = false;
	else if (pantalla[x][y] != '0')
		return (true);
	if (ft_isborder(x, y, rows, (int)ft_strlen(pantalla[x])))
	{
		*isclosed = false;
	}
	pantalla[x][y] = 'C';
	ft_floodfillutil(pantalla, x + 1, y, isclosed);
	ft_floodfillutil(pantalla, x - 1, y, isclosed);
	ft_floodfillutil(pantalla, x, y -1, isclosed);
	ft_floodfillutil(pantalla, x, y +1, isclosed);
	return (*isclosed);
}

/**
 * Copies the map data and prepares it for the flood fill algorithm.
 *
 * This function duplicates the map data from the game data structure,
 * converting spaces to 'H' to indicate holes or open areas.
 *
 * @param data The game data structure containing the original map.
 * @param rows The number of rows in the map.
 * @return Returns a new 2D array with the modified map data.
 */
static char	**ft_copy_map_data(t_data data, int rows)
{
	char	**pantalla;
	int		i;
	int		j;

	pantalla = ft_calloc(rows + 1, sizeof(char *));
	i = 0;
	while (i < rows)
	{
		pantalla[i] = ft_strdup(data.map2d[i]);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < (int)ft_strlen(pantalla[i]))
		{
			if (pantalla[i][j] == ' ')
				pantalla[i][j] = 'H';
			j++;
		}
		i++;
	}
	pantalla[rows] = NULL;
	return (pantalla);
}

/**
 * Frees the memory allocated for the modified map data.
 *
 * This function deallocates the memory for each row of the map and
 * then frees the array itself.
 *
 * @param pantalla The 2D array containing the modified map data.
 * @param rows The number of rows in the map.
 */
static void	ft_free_pantalla(char **pantalla, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(pantalla[i]);
		i++;
	}
	free(pantalla);
}
