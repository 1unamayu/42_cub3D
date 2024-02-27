/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 14:24:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

/**
 * Extracts a texture path from a map file for a given direction.
 *
 * @param texture A pointer to a character pointer where the extracted texture
 *        path will be stored.
 * @param filename The path to the map file.
 * @param direction A two-letter string representing the texture direction
 *        ("NO", "SO", "WE", or "EA").
 *
 * @return A pointer to the allocated string containing the texture path,
 *         or NULL if the texture is not found or an error occurs.
 *
 * This function searches for a line in the map file specified by `filename`
 * that begins with the given `direction` string followed by a space. If such
 * a line is found, the function extracts the string after the space and
 * stores it in the memory pointed to by `texture`. The function is responsible
 * for allocating the memory for the extracted path.
 *
 */
char	*ft_parse_map_texture(char **texture, char *filename, char *direction)
{
	char	**elements;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], direction, 2) == 0)
		{
			*texture = ft_strdup(elements[1]);
			free(line);
			ft_free_split(elements);
			break ;
		}
		free(line);
		ft_free_split(elements);
		line = get_next_line(fd);
	}
	close(fd);
	return (NULL);
}
