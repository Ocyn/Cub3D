/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:43:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 03:00:14 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	me_set_color(int *src, size_t red, size_t green, size_t blue)
{
	if (!src)
		return ;
	if (red <= 256)
		src[0] = red;
	if (green <= 256)
		src[1] = green;
	if (blue <= 256)
		src[2] = blue;
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
	id = -1;
	new = s_malloc(sizeof(char *) * (src_len + 1));
	while (++id < src_len)
	{
		new[id] = s_malloc(sizeof(char) * (ylen + 1));
		if (!new[id])
			return (s_freetab(new, id));
		new[id] = (char *)ft_memset((char *)new[id], ' ', ylen);
		ft_strlcpy(new[id], src[id], ft_strlen(src[id]));
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
