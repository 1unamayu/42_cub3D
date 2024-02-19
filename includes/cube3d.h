/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:43 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 14:37:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "map.h"
# include "get_next_line.h"
# include "parser.h"
int	ft_is_valid_input_file(char *arguments[]);
int ft_is_valid_map(const char *filename);
int	ft_is_valid_line(int position, const char *line, int n_lines);
int	ft_is_valid_texture_line(const char *direction, const char *line);
int ft_is_color_line(const char *type, const char *line);
int	ft_is_valid_map_line(int position, const char *line, int nlines);
/*int ft_is_valid_first_map_line(const char *line);
int ft_is_valid_inter_map_line(const char *line);
int ft_is_valid_last_map_line(const char *line);*/
int	ft_line_has_only_6(const char *str);
int	ft_line_has_only_1(const char *str);
//utils
int	ft_is_valid_filename(const char *filename);
int	ft_count_files(const char *filename);
int	ft_is_valid_file_extension(const char *filename, const char *extension);
char *ft_str_remove_newline(char *str);
int ft_line_all_spaces(const char *line);
int ft_show_error(const char *error_text);
#endif
