/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:01:07 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:48:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

static void	assign_color_values(t_color *color, char **colors);

/**
 * Extracts a color value from a map file for a given type.
 *
 * @param color A pointer to a `t_color` structure where the extracted
 *        color values will be stored.
 * @param filename The path to the map file.
 * @param type A one-letter string representing the color type
 *        ("C" for ceiling, "F" for floor).
 *
 * @return A pointer to the allocated string containing the parsed color
 *         values, or NULL if the color is not found or an error occurs.
 *
 * This function searches for a line in the map file specified by `filename`
 * that begins with the given `type` character followed by a space. If such
 * a line is found, the function extracts the RGB color values separated by
 * commas and stores them in the `t_color` structure pointed to by `color`.
 *
 */
char	*ft_parse_map_color(t_color *color, char *filename, char *type)
{
	char	**elements;
	char	*line;
	int		fd;
	char	**colors;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], type, 1) == 0)
		{
			colors = ft_split(elements[1], ',');
			assign_color_values(color, colors);
			ft_free_split(colors);
			ft_free_split(elements);
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
		ft_free_split(elements);
	}
	return (NULL);
}

/**
 * Assigns RGB color values to a t_color structure.
 *
 * @param color A pointer to a t_color structure.
 * @param colors An array of strings representing RGB values.
 */
static void	assign_color_values(t_color *color, char **colors)
{
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
}
