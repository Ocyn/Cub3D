/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:45:16 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/12 16:23:37 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 200

size_t	gnl_strlen(char *s);
char	*get_next_line(int fd);
char	*gnl_strchr(char *s, char c);
char	*gnl_strncpy(char *dst, char *src, size_t len);
char	*gnl_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);

#endif