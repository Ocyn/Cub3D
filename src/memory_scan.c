/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/13 19:31:44 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	me_scan_digit(char *s)
{
	char	**temp;
	int		i;

	i = -1;
	temp = ft_split(s, ' ');
	if (me_tablen(temp) > 1)
		return (s_freetab(temp, me_tablen(temp)), 1);
	s_freetab(temp, me_tablen(temp));
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ')
			return (1);
	}
	return (0);
}

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

void	me_diffusion2(char **tab, long my, long mx, char limit)
{
	while (tab && tab[my] && tab[my][mx] \
	&& tab[my][mx] != limit && tab[my][mx] != '*')
	{
		while (tab && tab[my] && tab[my][mx + 1] \
		&& tab[my][mx + 1] != limit && tab[my][mx + 1] != '*')
			tab[my][mx++] = '*';
		while (tab && tab[my + 1] && tab[my + 1][mx] \
		&& tab[my + 1][mx] != limit && tab[my + 1][mx] != '*')
			tab[my++][mx] = '*';
		while (tab && tab[my] && tab[my][mx - 1] \
		&& tab[my][mx - 1] != limit && tab[my][mx - 1] != '*')
		{
			mx -= (mx > 0);
			tab[my][mx] = '*';
		}
		while (tab && tab[my - 1] && tab[my - 1][mx] \
		&& tab[my - 1][mx] != limit && tab[my - 1][mx] != '*')
		{
			my -= (my > 0);
			tab[my][mx] = '*';
		}
	}
	return ;
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
