/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:37:32 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/03 23:40:21 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
