/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:47:02 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 18:06:36 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, char c)
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

char	*ft_gnl_strncpy(char *dst, char *src, size_t len)
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

char	*ft_gnl_strdup(char *src)
{
	char	*new;

	new = NULL;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * (ft_gnl_strlen(src) + 1));
	if (!new)
		return (NULL);
	ft_gnl_strncpy(new, src, ft_gnl_strlen(src));
	return (new);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len1;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_gnl_strdup(s1));
	if (!s1 && s2)
		return (ft_gnl_strdup(s2));
	len1 = ft_gnl_strlen(s1);
	new = malloc(sizeof(char) * (len1 + ft_gnl_strlen(s2) + 1));
	if (!new)
		return (NULL);
	ft_gnl_strncpy(new, s1, len1);
	new += len1;
	ft_gnl_strncpy(new, s2, ft_gnl_strlen(s2));
	new -= len1;
	free(s1);
	return (new);
}
