/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safemode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:36:41 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/09 23:46:44 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sf_while(char **tab)
{
	long long	y;

	if (!tab || !tab[0])
		return ;
	y = 0;
	if (ft_strchr(tab[0], '*'))
		return ((void)printf("KO\n"));
	while (tab && tab[y])
	{
		printf("line %lld  \t", y);
		if (tab[y][0] == '*' || tab[y][ft_strlen(tab[y]) - 1] == '*')
			return ((void)printf("KO\n"));
		y++;
		printf("OK\n");
	}
	if (ft_strchr(tab[y - (tab[y - 1] != NULL)], '*'))
		return ((void)printf("KO\n"));
}

void	sf_safemode(t_data data)
{
	char	**tmap;

	tmap = NULL;
	(void)data;
	printf("\n");
	db_beacon("Safe Mode", 41);
	printf("Cloning map\t");
	tmap = me_tabdup(data.map.map, me_tablen(data.map.map));
	if (!tmap)
		return ((void)printf("KO\n"));
	printf("OK\n");
	db_showtab(tmap);
	printf("Launching diffusion\t");
	me_diffusion(tmap, data.player.ypos, data.player.xpos, '1');
	if (!tmap)
		return ((void)printf("KO\n"));
	printf("OK\n");
	db_showtab(tmap);
	sf_while(tmap);
	tmap = s_freetab(tmap, me_tablen(tmap));
	db_beacon("END", 41);
}
