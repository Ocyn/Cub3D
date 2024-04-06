/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_edit_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:03:20 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 00:24:44 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*me_str_edit_init(char **src, char *seek, char *replace, int *llen);
static int		me_str_occur(const char *src, const char *seek);

void	me_str_edit(char **src, char *seek, char *replace)
{
	char	*new;
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = *src;
	new = me_str_edit_init(src, seek, replace, &len);
	while (i < len)
	{
		if (me_str_occur(str + i, seek))
		{
			i += me_strcat(new, replace);
			str += ft_strlen(seek) - ft_strlen(replace);
		}
		else
		{
			new[i] = str[i];
			i++;
		}
	}
	free(*src);
	*src = new;
}

static char	*me_str_edit_init(char **src, char *seek, char *replace, int *llen)
{
	char	*new;
	char	*str;
	int		len;
	int		i;

	i = -1;
	len = 0;
	str = *src;
	new = NULL;
	while (str && str[++i])
		if (me_str_occur(str + i, seek))
			len++;
	i = 0;
	len = ft_strlen(*src) + (len * (ft_strlen(replace) - ft_strlen(seek)));
	new = s_malloc(sizeof(char) * (len + 1));
	*llen = len;
	return (new);
}

static int	me_str_occur(const char *src, const char *seek)
{
	int	i;
	int	len_src;
	int	len_seek;

	i = 0;
	if (!src || !seek)
		return (0);
	len_src = (int)ft_strlen(src);
	len_seek = (int)ft_strlen(seek);
	while (i < len_src && i < len_seek && src[i] && src[i] == seek[i])
		i++;
	if (i == len_seek)
		return (1);
	return (0);
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
