/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safemode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:36:41 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 02:47:45 by jcuzin           ###   ########.fr       */
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
	long long	cord[2];

	(void)data;
	printf("\n");
	db_beacon("Safe Mode", 41);
	db_showplayer(data.player);
	misc_player_location(data.map, &cord[0], &cord[1]);
	printf("\nCoord = [%lld][%lld]\n", cord[0], cord[1]);
	db_beacon("END", 41);
}
