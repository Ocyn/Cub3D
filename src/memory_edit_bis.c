/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:03:20 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/26 11:24:08 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*me_auto_joinstr(char *s1, char *s2, int frees)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (frees == 1 || frees == 3)
		free(s1);
	if (frees == 2 || frees == 3)
		free(s2);
	return (new);
}

void	me_memset_pix(char *p, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((int *)p)[i] = c;
		i++;
	}
}

size_t	*me_tabedit(size_t *tab, size_t one, size_t two)
{
	tab[0] = one;
	tab[1] = two;
	return (tab);
}

int	me_strcat(char *dest, char *src)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen((char *)dest);
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = 0;
	return (i);
}

void	me_insert_tab_in_tab(char **insert, char ***tab, long where)
{
	char		**new;
	long		ins_;
	long		i;
	long		len;

	i = -1;
	ins_ = 0;
	new = NULL;
	len = me_tablen(*tab) + me_tablen(insert);
	if (!insert || !len || (long)me_tablen(*tab) < where)
		return ;
	new = s_malloc(sizeof(char *) * (len + 1));
	if (!new)
		return ;
	while (++i < len && i - ins_ >= 0 && (*tab)[i - ins_])
	{
		if (i == where - 1)
			while (insert[ins_])
				new[i++] = ft_strdup(insert[ins_++]);
		if (i - ins_ == where - 1)
			ins_ -= (ins_ <= i);
		new[i] = ft_strdup((*tab)[i - ins_]);
	}
	s_freetab(*tab, me_tablen(*tab));
	*tab = new;
}
