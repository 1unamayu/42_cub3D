/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:21:39 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/26 19:50:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCT_H
# define GAME_STRUCT_H

# define W_RESOL 800
# define H_RESOL 700

typedef struct s_texture
{
	char	*texture_path;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data //the data structure
{
	char		**map2d;	// the map
	int			p_x;		// player x position in the map
	int			p_y;		// player y position in the map
	int			w_map;		// map width
	int			h_map;		// map height
	t_color		c_floor;	// floor color
	t_color		c_celing;	// celing color
	t_texture	t_no;		// North texture
	t_texture	t_so;		// South texture
	t_texture	t_we;		// West texture
	t_texture	t_ea;		// East textue
}	t_data;
#endif