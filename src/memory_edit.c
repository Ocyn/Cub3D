/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:43:23 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 00:24:44 by jcuzin           ###   ########.fr       */
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
