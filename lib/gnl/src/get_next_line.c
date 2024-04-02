/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:26 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 21:25:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	*gnl_bzero(char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
	return (NULL);
}

void	*gnl_free(void *data)
{
	if (data)
		free(data);
	return (NULL);
}

size_t	gnl_read(int fd, char *buff, size_t len)
{
	size_t	rlen;

	rlen = 0;
	gnl_bzero(buff, len);
	rlen = read(fd, buff, len);
	return (rlen);
}

size_t	gnl_parse(int fd, char *line, char *buff, size_t *rlen)
{
	*rlen = gnl_read(fd, buff, BUFFER_SIZE);
	while (!gnl_strchr(line, '\n') && *rlen > 0)
	{
		line = gnl_strjoin(line, buff);
		*rlen = gnl_read(fd, buff, BUFFER_SIZE);
	}
	return (gnl_strlen(line));
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	size_t		rlen;

	line = NULL;
	rlen = 0;
	if (fd < 2)
		return (NULL);
	if (gnl_strlen(buff))
		line = gnl_strdup(buff);
	while (!gnl_strchr(line, '\n') && (rlen = gnl_read(fd, buff, BUFFER_SIZE)) > 0)
		line = gnl_strjoin(line, buff);
	if (!gnl_strlen(line))
		return (gnl_free(line), gnl_bzero(buff, BUFFER_SIZE));
	rlen = gnl_strlen(gnl_strchr(line, '\n'));
	if (rlen)
	{
		gnl_strncpy(buff, gnl_strchr(line, '\n') + 1, rlen);
		rlen = (gnl_strlen(line) + 1) - rlen;
	}
	else
	{
		gnl_bzero(buff, BUFFER_SIZE);
		rlen = gnl_strlen(line);
	}
	line[rlen] = 0;
	return (line);
}
