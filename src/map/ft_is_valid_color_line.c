/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_color_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:05:50 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 12:19:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	ft_is_color_element(char *argument);

/**
 * @brief Validates a line representing a color specification.
 *
 * This function determines if a line in a configuration file is a valid color
 * specification based on its format and content. A valid color specification
 * has the following structure:
 *
 * ```
 * type R,G,B
 * ```
 *
 * where:
 * - `type`: A single-character string representing the color type.
 * - `R`, `G`, `B`: Integers separated by commas (range 0-255).
 *
 * The function performs the following checks:
 *
 * 1. **Number of arguments:**
 *      Ensures there are exactly two arguments separated by space.
 * 2. **Color type:**
 *      Verifies that the first argument is a single-character string 
 *      and matches the expected `type`.
 * 3. **RGB values:**
 *      Calls `ft_is_color_element` to validate the format
 *  	and range of the comma-separated RGB values.
 *
 * If all checks pass, the function returns `TRUE`.
 * Otherwise, it returns `FALSE` and sets an error message using `ft_show_error`.
 *
 * @param type Pointer to a null-terminated character string 
 *			   representing the expected color type.
 * @param line Pointer to a null-terminated character string 
 *             containing the line to be validated.
 *
 * @return `TRUE` if the line is a valid color specification, `FALSE` otherwise.
 */
int	ft_is_color_line(const char *type, const char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (ft_2d_array_size(data) != 2)
	{
		free(data);
		return (ft_show_error("To many arguments in line"));
	}
	if (ft_strncmp(data[0], type, 1) != 0 || ft_strlen(data[0]) != 1)
	{
		free(data);
		return (ft_show_error("Error in color line"));
	}
	if (ft_is_color_element(data[1]) == FALSE)
	{
		free(data);
		return (ft_show_error("Error in color line"));
	}
	free(data);
	return (TRUE);
}

/**
 * @brief Validates a string containing comma-separated RGB color values.
 *
 * This function checks if a string is a valid representation
 * of RGB color values, expecting three integers separated by commas
 * and ranging from 0 to 255.
 *
 * @param argument Pointer to a null-terminated character string
 *                 containing the color values (e.g., "128,255,0").
 *
 * @return `TRUE` if the string is a valid RGB color representation,
 *         `FALSE` otherwise.
 */
static int	ft_is_color_element(char *argument)
{
	char	**data;
	int		i;

	data = ft_split(argument, ',');
	if (ft_2d_array_size(data) != 3)
	{
		free(data);
		return (ft_show_error("Not RGB data"));
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(data[i]) < 0 || ft_atoi(data[i++]) > 255)
		{
			free(data);
			return (ft_show_error("Not RGB data"));
		}
	}
	free(data);
	return (TRUE);
}
