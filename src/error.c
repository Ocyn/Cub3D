/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:46:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 22:31:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	err_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str && str[0] && str++)
		len += write(fd, &str[0], 1);
	return (len);
}

int	err_stderr(int launch)
{
	if (!launch)
		return (EXIT_FAILURE);
	perror("Cub3D");
	return (EXIT_SUCCESS);
}

int	err_custom(int launch, char *log, char *font)
{
	if (!launch)
		return (EXIT_FAILURE);
	if (!font)
		err_putstr_fd("\033[0;91m", 2);
	else
		err_putstr_fd(font, 2);
	err_putstr_fd("ERROR", 2);
	err_putstr_fd("\033[0m", 2);
	err_putstr_fd(" - ", 2);
	err_putstr_fd(log, 2);
	printf("%sERROR%s - %s\n", font, "\033[0m", log);
	return (EXIT_SUCCESS);
}
