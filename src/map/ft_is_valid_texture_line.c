/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_texture_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:38:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 11:54:53 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/**
 * @brief Validates a line representing a texture specification.
 *
 * This function determines if a line in a configuration file is a valid texture
 * specification by checking its format and content.
 * A valid texture specification has the following structure:
 *
 * ```
 * direction filename
 * ```
 *
 * where:
 * - `direction`: A two-character string representing the texture direction.
 * - `filename`: The path to the texture image file.
 *
 * The function performs the following checks:
 *
 * 1. **Number of arguments:**
 *		Ensures there are exactly two arguments separated by space.
 * 2. **Direction format:** 
 *      Verifies that the first argument is a two-character string 
 *      and matches the expected direction format.
 * 3. **Filename validity:**
 *      Calls `ft_is_valid_filename` to validate the filename.
 *
 * If all checks pass, the function returns `TRUE`.
 * Otherwise, it returns `FALSE` and sets an error message using `ft_show_error`.
 *
 * @param direction Pointer to a null-terminated character string
 *                  representing direction.
 * @param line Pointer to a null-terminated character string
 *			   containing the line.
 *
 * @return `TRUE` if the line is a valid texture specification,
 *			`FALSE` otherwise.
 */
int	ft_is_valid_texture_line(const char *direction, const char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (ft_2d_array_size(data) != 2)
	{
		free(data);
		return (ft_show_error("To many arguments in line"));
	}
	if (ft_strncmp(data[0], direction, 2) != 0 || ft_strlen(data[0]) != 2)
	{
		free(data);
		return (ft_show_error("Texture direction error."));
	}
	if (ft_is_valid_filename(ft_str_remove_newline(data[1])) == FALSE)
	{
		free(data);
		return (ft_show_error("Texture filename error."));
	}
	free(data);
	return (TRUE);
}
