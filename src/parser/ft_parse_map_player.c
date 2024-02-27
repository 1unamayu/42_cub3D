/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:18:37 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:52 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

static void	ft_parse_line_player(int *pos_x, int *pos_y, char *line, int row);

/**
 * Parses a map file to extract the player's starting position.
 *
 * @param pos_x Pointer to store the player's X-coordinate (row).
 * @param pos_y Pointer to store the player's Y-coordinate (column).
 * @param filename Path to the map file.
 *
 * @return None (void function).
 *
 * This function reads the `filename` map file and searches for a line containing
 * one of the valid player characters ('N', 'S', 'W', or 'E'). If found, the
 * function stores the corresponding row and column coordinates
 * in the `pos_x` and `pos_y` variables.
 * It assumes that `ft_parse_line_player` is used to process each line 
 * and update the player position.
 *
 */
void	ft_parse_map_player(int *pos_x, int*pos_y, char *filename)
{
	char	*line;
	int		fd;
	char	*lineclear;
	int		cont;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	cont = 0;
	while (line != NULL)
	{
		lineclear = ft_strtrim(line, " ");
		if (lineclear[0] == '1' || lineclear[0] == '0')
		{
			ft_parse_line_player(pos_x, pos_y, lineclear, cont);
			cont++;
		}
		free(line);
		free(lineclear);
		line = get_next_line(fd);
	}
}

/**
 * Parses a single line of the map to find the player's starting position.
 *
 * This function searches through a given line for the characters 'N', 'S', 'W',
 * or 'E', which represent the player's starting position and orientation. If one
 * of these characters is found, it updates the player's position coordinates.
 *
 * @param pos_x Pointer to an integer where the player's row (x-coordinate) will
 *              be stored.
 * @param pos_y Pointer to an integer where the player's column (y-coordinate)
 *              will be stored.
 * @param line The current line of the map being parsed.
 * @param row The row number of the current line in the map, used to set the
 *            player's x-coordinate.
 *
 * Note: The function checks for the presence of player direction indicators
 *       ('N', 'S', 'W', 'E') and updates the position coordinates accordingly.
 *       It assumes that there is at most one player position indicator per line.
 */
static void	ft_parse_line_player(int *pos_x, int *pos_y, char *line, int row)
{
	size_t	i;

	i = 0;
	if (ft_strchrc(line, 'N') != 0 || ft_strchrc(line, 'S') != 0 || \
		ft_strchrc(line, 'W') != 0 || ft_strchrc(line, 'W') != 0)
	{
		*pos_x = row;
		while (i < ft_strlen(line))
		{
			if (line[i] == 'N' || line[i] == 'W' || \
				line[i] == 'S' || line[i] == 'E')
			{
				*pos_y = (int) i;
				break ;
			}
			i++;
		}
	}
}
