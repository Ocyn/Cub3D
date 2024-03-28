/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:26 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 23:50:46 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	s_read(int fd, char *buff, size_t len)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] && i < len)
	{
		buff[i] = 0;
		i++;
	}
	i = read(fd, buff, len);
	return (i);
}

char	*ft_parser(int fd, char *line, char *nbuff, size_t *rlen)
{
	char	*buff;

	buff = nbuff;
	*rlen = s_read(fd, buff, BUFFER_SIZE);
	while (!ft_gnl_strchr(line, '\n') && *rlen > 0)
	{
		line = ft_gnl_strjoin(line, buff);
		*rlen = s_read(fd, buff, BUFFER_SIZE);
	}
	nbuff = buff;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	size_t		rlen;

	line = NULL;
	rlen = 0;
	if (ft_gnl_strlen(buff))
		line = ft_gnl_strdup(buff);
	line = ft_parser(fd, line, buff, &rlen);
	if (!ft_gnl_strlen(line))
		return (free(line), NULL);
	rlen = ft_gnl_strlen(ft_gnl_strchr(line, '\n'));
	if (rlen)
	{
		ft_gnl_strncpy(buff, ft_gnl_strchr(line, '\n') + 1, rlen);
		rlen = (ft_gnl_strlen(line) + 1) - rlen;
	}
	else
	{
		ft_gnl_strncpy(buff, "", rlen);
		rlen = ft_gnl_strlen(line);
	}
	line[rlen] = 0;
	return (line);
}
