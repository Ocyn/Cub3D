/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:43:30 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/17 21:53:30 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char	***ff_init(char **tab)
{
	char	***div;
	long	len;
	long	unit;
	long	u;

	len = me_tablen(tab) * ft_strlen(tab[0]);
	if (len < 1000)
		return (NULL);
	unit = len / 1000;
	div = s_malloc(sizeof(char **) * (unit + 2));
	if (!div)
		return (NULL);
	u = -1;
	len = 1000 / (ft_strlen(tab[0]));
	printf("tab will be divided by %zu tab of %ld lines each\n", unit + 1, len);
	while (++u < unit)
	{
		div[u] = me_tabdup(tab + (len * u), len);
		printf("Div %zu created\n", u);
	}
	div[unit] = me_tabdup(tab + (len * u), me_tablen(tab + (len * u)));
	printf("Div %zu created\n", u);
	div[unit + 1] = NULL;
	for (long i = 0; div && div[i]; i++)
	{
		for (long i2 = 0; div && div[i] && div[i][i2]; i2++)
			printf(" %zu %zu [%s]\n", i, i2, div[i][i2]);
	}
	return (div);
}

int	ff_diffusion(char **tab, long my, long mx, char limit)
{
	long	cord[2];
	char	***div;
	int		u;

	div = ff_init(tab);
	if (!div)
		return (ff_diffusion(tab, my, mx, limit), 0);
	printf("\nMulti Recursive\n\n");
	u = -1;
	while (div[++u])
	{
		cord[0] = me_find_str_in_tab(0, "0", div[u]);
		cord[1] = me_find_str_in_str(div[u][cord[0]], "0");
		printf("Diffuse %d start at [%ld][%ld]\n", u, cord[0], cord[1]);
		ff_recur_diffusion(div[u], cord[0], cord[1], limit);
	}
	for (long i = 0; div && div[i]; i++)
	{
		for (long i2 = 0; div && div[i] && div[i][i2]; i2++)
			printf(" %zu %zu [%s]\n", i, i2, div[i][i2]);
	}
	u = -1;
	while (div[++u])
	{
		s_freetab(div[u], me_tablen(div[u]));
	}
	free(div);
	return 0;
}
