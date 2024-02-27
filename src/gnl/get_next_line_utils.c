/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:47:34 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/21 13:35:34 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_createline(char *src, int len)
{
	int		i;
	char	*dst;

	if ((!src) || (len == 0))
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr_g(char *s, int start, int len)
{
	char	*aux;
	int		i;
	int		z;

	i = start;
	if ((i >= ft_strlen_g(s)) || (len == 0) || (!s))
	{
		free(s);
		return (NULL);
	}
	z = 0;
	if (len > ft_strlen_g(s))
		len = ft_strlen_g(s);
	aux = (char *) malloc(len + 1);
	if (!aux)
		return (0);
	while (z < len)
	{
		aux[z] = s[i];
		z++;
		i++;
	}
	aux[z] = '\0';
	free(s);
	return (aux);
}

int	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 00)
		i++;
	return (i);
}
