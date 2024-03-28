/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:33:20 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 16:32:33 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	cursor;
	char			*str;

	cursor = 0;
	if (size != 0 && count > SSIZE_MAX / size)
		return (0);
	str = malloc(size * count);
	if (str == NULL)
		return (NULL);
	while (cursor < (size * count))
		str[cursor++] = 0;
	return ((void *) str);
}
