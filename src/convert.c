/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:37:32 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/12 16:25:47 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	conv_rgb(int i[3])
{
	return (i[0] << 16 | i[1] << 8 | i[2]);
}

int	conv_rgbtab(int red, int green, int blue)
{
	int		i[3];

	i[0] = red;
	i[1] = green;
	i[2] = blue;
	return (conv_rgb(i));
}

char	**conv_file2tab(char *file)
{
	int		fd;
	size_t	id;
	size_t	tlen;
	char	**tab;

	id = 0;
	tlen = me_filelen(file);
	if (!tlen)
		return (NULL);
	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(char *) * (tlen + 1));
	while (tab && id < tlen)
	{
		tab[id] = get_next_line(fd);
		if (!tab[id])
			break ;
		id++;
	}
	tab[tlen] = NULL;
	close(fd);
	return (tab);
}
