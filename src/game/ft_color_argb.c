/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_argb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:05:29 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/26 20:12:39 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Converts a color from the t_color format to an integer representing 
 * the color in ARGB format.
 * 
 * @param color A t_color structure that contains the red, green, 
 *              and blue components of the color.
 * @return A 32-bit integer where the most significant byte is alpha
 *         (always set to 0xFF), followed by the red, green, and blue
 *  components of the color.
 */
int	ft_to_color_argb(t_color color)
{
	int	color_argb;

	color_argb = (0xFF << 24) | (color.r << 16) | (color.g << 8) | color.b;
	return (color_argb);
}
