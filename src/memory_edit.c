/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:43:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/12 18:04:55 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	me_set_color(int *src, size_t red, size_t green, size_t blue)
{
	if (!src)
		return (err_return(EXIT_FAILURE, "Color code unavailable", 4));
	if (red > 256 || green > 256 || blue > 256 \
	|| red < 0 || green < 0 || blue < 0)
		return (err_return(EXIT_FAILURE, "Invalid color code", 4));
	if (red <= 256)
		src[0] = red;
	if (green <= 256)
		src[1] = green;
	if (blue <= 256)
		src[2] = blue;
	return (EXIT_SUCCESS);
}

char	**me_tabdup_ratio(char **src, long long src_len)
{
	char		**new;
	long long	ylen;
	long long	id;

	id = -1;
	ylen = 0;
	new = NULL;
	while (++id < src_len)
	{
		if ((long long)ft_strlen(src[id]) + 1 > ylen)
			ylen = ft_strlen(src[id]) + 1;
	}
	new = s_malloc(sizeof(char *) * (src_len + 1));
	id = -1;
	while (++id < src_len)
	{
		new[id] = s_malloc(sizeof(char) * (ylen + 3));
		if (!new[id])
			return (s_freetab(new, id));
		new[id] = (char *)ft_memset((char *)new[id], ' ', ylen + 2);
		ft_strlcpy(new[id] + 2, src[id], ft_strlen(src[id]));
	}
	return (new);
}

char	**me_tabdup(char **src, size_t src_len)
{
	char	**new;
	size_t	id;

	id = 0;
	new = NULL;
	new = s_malloc(sizeof(char *) * (src_len + 1));
	while (id < src_len)
	{
		new[id] = ft_strdup(src[id]);
		if (!new[id])
		{
			s_freetab(new, id);
			return (NULL);
		}
		id++;
	}
	return (new);
}
