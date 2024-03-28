/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:45:16 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 18:06:36 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 25

size_t	ft_gnl_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_gnl_strchr(char *s, char c);
char	*ft_gnl_strncpy(char *dst, char *src, size_t len);
char	*ft_gnl_strdup(char *src);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif