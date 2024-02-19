/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:16:21 by javigarc          #+#    #+#             */
/*   Updated: 2022/02/03 21:51:17 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_addbuffer(char *ldr, char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = ft_strlen_g(ldr);
	j = 0;
	aux = (char *) malloc(sizeof(char) * (i + ft_strlen_g(buff) + 1));
	if (!aux)
		return (NULL);
	while (ldr[j])
	{
		aux[j] = ldr[j];
		j++;
	}
	j = 0;
	while (buff[j])
	{
		aux[i] = buff[j];
		i++;
		j++;
	}
	aux[i] = 00;
	free(ldr);
	free(buff);
	return (aux);
}

int	ft_readfile(int fdr, char **ldr)
{
	char	*buffer;
	int		byts;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	byts = read (fdr, buffer, BUFFER_SIZE);
	if (byts == 0)
	{
		free(buffer);
		return (0);
	}
	if (byts > 0)
	{
		buffer[byts] = '\0';
		if (!*ldr)
			*ldr = buffer;
		else
			*ldr = ft_addbuffer(*ldr, buffer);
	}
	if (byts < 0)
		free(buffer);
	return (byts);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*loader;
	int			end;
	int			bytes;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	end = 0;
	bytes = 1;
	while ((end == 0) && (bytes != 0))
	{
		bytes = ft_readfile(fd, &loader);
		if ((bytes < 0) || ((!loader) && (bytes == 0)))
			return (NULL);
		end = ft_searchend(loader, '\n');
	}
	if (end == 0)
		end = ft_strlen_g(loader);
	line = ft_createline(loader, end);
	loader = ft_substr_g(loader, end, ft_strlen_g(loader) - end);
	return (line);
}

int	ft_searchend(char *str, int tofind)
{
	char	ctofind;
	int		i;

	ctofind = (char) tofind;
	i = 0;
	while (str[i])
	{
		if (str[i] == ctofind)
			return (i + 1);
		i++;
	}
	return (0);
}
