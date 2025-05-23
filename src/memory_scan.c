/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/18 20:58:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	me_scan_digit(char *s)
{
	char	**temp;
	int		i;

	i = -1;
	temp = ft_split(s, ' ');
	if (ft_atoi(s) < 0 || ft_atoi(s) > 255)
		return (1);
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

void	ff_recur_diffusion(char **tab, long my, long mx, char limit)
{
	if (tab && tab[my] && tab[my][mx] \
	&& tab[my][mx] != limit && tab[my][mx] != '*')
	{
		tab[my][mx] = '*';
		ff_recur_diffusion(tab, my, mx + 1, limit);
		ff_recur_diffusion(tab, my, mx - (mx > 0), limit);
		ff_recur_diffusion(tab, my + 1, mx, limit);
		ff_recur_diffusion(tab, my - (my > 0), mx, limit);
	}
	return ;
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
