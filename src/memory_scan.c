/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 22:17:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	me_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && s2)
		return (-1);
	if (s1 && !s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	me_find_str_in_tab(int strict_mode, char *find, char **tab)
{
	int	i;

	i = -1;
	if (!find || !tab)
		return (-1);
	while (find && tab && tab[++i])
	{
		if (me_find_str_in_str(tab[i], find))
			if (!strict_mode || (strict_mode && !me_strcmp(tab[i], find)))
				return (i);
	}
	return (-1);
}

int	me_find_str_in_str(const char *src, const char *seek)
{
	int	i;
	int	find;

	i = 0;
	if (!src || !seek)
		return (-1);
	while (src[i])
	{
		find = 0;
		while (src[find + i] && src[find + i] == seek[find])
		{
			find++;
			if (!seek[find])
				return (i);
		}
		i++;
	}
	return (-1);
}

size_t	me_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

size_t	me_filelen(int fd)
{
	size_t	len;
	char	*line;

	len = 0;
	line = NULL;
	if (fd < 2)
		return (0);
	while (fd > 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		len++;
	}
	close(fd);
	return (len);
}
