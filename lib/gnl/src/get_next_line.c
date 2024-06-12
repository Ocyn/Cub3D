/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:24:26 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/03 18:12:48 by jcuzin           ###   ########.fr       */
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

size_t	gnl_read(size_t *rlen, int fd, char *buff, size_t len)
{
	gnl_bzero(buff, len);
	*rlen = read(fd, buff, len);
	return (*rlen);
}

void	gnl_parse(char *line, char *buff, size_t *rlen)
{
	if (*rlen)
	{
		gnl_strncpy(buff, gnl_strchr(line, '\n') + 1, *rlen);
		*rlen = (gnl_strlen(line) + 1) - *rlen;
	}
	else
	{
		gnl_bzero(buff, BUFFER_SIZE);
		*rlen = gnl_strlen(line);
	}
	line[*rlen] = 0;
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
	while (!gnl_strchr(line, '\n') \
	&& gnl_read(&rlen, fd, buff, BUFFER_SIZE) > 0)
		line = gnl_strjoin(line, buff);
	if (!gnl_strlen(line))
		return (gnl_free(line), gnl_bzero(buff, BUFFER_SIZE));
	rlen = gnl_strlen(gnl_strchr(line, '\n'));
	gnl_parse(line, buff, &rlen);
	return (line);
}
