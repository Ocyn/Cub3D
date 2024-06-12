/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:47:02 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 21:25:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*gnl_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dst);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*gnl_strdup(char *src)
{
	char	*new;

	new = NULL;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * (gnl_strlen(src) + 1));
	if (!new)
		return (NULL);
	gnl_strncpy(new, src, gnl_strlen(src));
	return (new);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len1;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (gnl_strdup(s1));
	if (!s1 && s2)
		return (gnl_strdup(s2));
	len1 = gnl_strlen(s1);
	new = malloc(sizeof(char) * (len1 + gnl_strlen(s2) + 1));
	if (!new)
		return (NULL);
	gnl_strncpy(new, s1, len1);
	new += len1;
	gnl_strncpy(new, s2, gnl_strlen(s2));
	new -= len1;
	free(s1);
	return (new);
}
