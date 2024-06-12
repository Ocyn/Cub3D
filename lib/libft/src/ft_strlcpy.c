/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:54:01 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 00:56:12 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	cursor;

	cursor = 0;
	if (!size)
		return (0);
	while (cursor < size)
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	return (ft_strlen(src));
}
