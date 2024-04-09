/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/09 23:10:14 by jcuzin           ###   ########.fr       */
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

size_t	me_strchrn(char *src, char seek)
{
	size_t		occur;
	size_t		i;

	occur = 0;
	i = 0;
	while (src && src[i])
	{
		occur += (src[i] == seek);
		i++;
	}
	return (occur);
}

void	me_diffusion(char **tab, long my, long mx, char limit)
{
	if (tab && tab[my] && tab[my][mx] \
	&& tab[my][mx] != limit && tab[my][mx] != '*')
	{
		tab[my][mx] = '*';
		me_diffusion(tab, my, mx + 1, limit);
		me_diffusion(tab, my, mx - (mx > 0), limit);
		me_diffusion(tab, my + 1, mx, limit);
		me_diffusion(tab, my - (my > 0), mx, limit);
	}
	return ;
}

int	me_str2strcmp(char *src, char *reg)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!src || !reg)
		return (1);
	while (src[i])
	{
		i2 = 0;
		while (reg[i2])
		{
			if (src[i] == reg[i2])
				break ;
			else if (!reg[i2 + 1])
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}
