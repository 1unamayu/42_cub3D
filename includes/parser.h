/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 11:19:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "get_next_line.h"
# include "game_struct.h"
# include <stdbool.h>

t_data	*ft_parse_map(char *filename);
int		ft_check_closed_map(t_data *game);
char	*ft_parse_map_color(t_color *color, char *filename, char *type);
char	*ft_parse_map_texture(char **texture, char *filename, char *direction);
void	ft_parse_map_lines(char **map2d, char *filename);
int		ft_count_map_lines(char *filename);
void	ft_parse_map_player(int *pos_x, int *pos_y, char *filename);
t_data	*ft_show_parse_error(const char *error_text);
void	ft_free_split(char **split);
void	ft_free_data(t_data *data);
bool	ft_is_region_closed(t_data data, char *filename);
void	ft_print_pantalla(char **pantalla, int rows);
#endif