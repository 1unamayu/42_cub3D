/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 22:09:45 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

/**
 * Parses lines from a map file and populates a 2D character array.
 *
 * @param map2d A 2D character array to store the parsed map lines.
 * @param filename The path to the map file.
 *
 * This function reads lines from the map file specified by `filename` and
 * stores them in the provided `map2d` array. Each line in the map file
 * represents a row of the map layout.
 *
 */
void	ft_parse_map_lines(char **map2d, char *filename)
{
	char	*line;
	int		fd;
	char	*lineclear;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		lineclear = ft_strtrim(line, " ");
		if (lineclear[0] == '1' || lineclear[0] == '0')
		{
			map2d[count] = ft_strdup(lineclear);
			count ++;
		}
		free(line);
		free(lineclear);
		line = get_next_line(fd);
	}
}
