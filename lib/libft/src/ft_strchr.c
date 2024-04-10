/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:58:40 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 03:34:37 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	id;

	id = 0;
	if (c > 256)
		c %= 256;
	if (!c)
		return ((char *)str + ft_strlen(str));
	while (str && str[id])
	{
		if (str[id] == c)
			return ((char *)str + id);
		id++;
	}
	return (NULL);
}
