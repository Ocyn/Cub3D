/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:43:30 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 10:27:17 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ff_check(char **tab, long my, long mx)
{
	return (my >= 0 && mx >= 0 && tab && tab[my] && tab[my][mx]);
}

int	ff_prefill(char **tab, long my, long mx, char limit)
{
	if (!ff_check(tab, my, mx) || tab[my][mx] == '*' || tab[my][mx] == limit)
		return (0);
	if (ff_check(tab, my, mx + 1) \
	&& tab[my][mx + 1] == '*')
		return (1);
	if (ff_check(tab, my + 1, mx) \
	&& tab[my + 1][mx] == '*')
		return (1);
	if (ff_check(tab, my, mx - 1) \
	&& tab[my][mx - 1] == '*')
		return (1);
	if (ff_check(tab, my - 1, mx) \
	&& tab[my - 1][mx] == '*')
		return (1);
	return (0);
}

void	ff_filling(char **tab, long my, long mx, char limit)
{
	if (ff_prefill(tab, my, mx, limit))
		tab[my][mx] = '*';
}

int	ff_isfilled(char **tab, char **sample)
{
	int	yy;

	yy = 0;
	if (!sample || !sample[0])
		return (0);
	while (tab && tab[yy] && sample && sample[yy])
	{
		if (ft_strncmp(tab[yy], sample[yy], ft_strlen(tab[yy])))
			return (0);
		yy++;
	}
	return (1);
}

void	ff_diffusion(char **tab, long my, long mx, char limit)
{
	char	**comp;
	int		yy;
	int		xx;

	comp = NULL;
	tab[my][mx] = '*';
	while (!ff_isfilled(tab, comp))
	{
		yy = 0;
		s_freetab(comp, me_tablen(comp));
		comp = me_tabdup(tab, me_tablen(tab));
		while (tab && tab[yy])
		{
			xx = 1;
			while (tab && tab[yy] && tab[yy][xx + 1])
			{
				ff_filling(tab, yy, xx, limit);
				xx++;
			}
			yy++;
		}
	}
	s_freetab(comp, me_tablen(comp));
}
