/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:03:20 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/24 19:08:32 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	*me_gentab(size_t one, size_t two)
{
	return ((size_t[2]){one, two});
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
