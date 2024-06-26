/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:45:00 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 05:54:48 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*s_free(char **ptr_memory)
{
	if (*ptr_memory && ptr_memory)
	{
		free(*ptr_memory);
		*ptr_memory = NULL;
	}
	return (NULL);
}

void	*s_malloc(unsigned long size)
{
	unsigned char	*byte_arr;
	void			*array;

	array = NULL;
	byte_arr = NULL;
	if (!size)
		return (NULL);
	array = malloc(size);
	if (!array)
		return (NULL);
	byte_arr = (unsigned char *)array;
	ft_memset(byte_arr, 0, size);
	return (byte_arr);
}

void	*s_freetab(char **tab, long i)
{
	if (tab)
	{
		while (i >= 0)
		{
			s_free(&tab[i]);
			i--;
		}
		s_free((char **)&tab);
	}
	return (NULL);
}
