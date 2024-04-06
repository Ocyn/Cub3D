/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:46:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 01:02:01 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	err_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str && str[0])
	{
		len += write(fd, &str[0], 1);
		str++;
	}
	return (len);
}

int	err_stderr(int launch)
{
	if (!launch)
		return (EXIT_FAILURE);
	perror("Cub3D");
	return (EXIT_SUCCESS);
}

int	err_custom(int launch, char *log, int tab)
{
	if (!launch)
		return (EXIT_SUCCESS);
	while (tab-- > 0)
		err_putstr_fd("\t", 2);
	err_putstr_fd(F_BOLD, 2);
	err_putstr_fd(F_RED, 2);
	err_putstr_fd("ERROR", 2);
	err_putstr_fd(F_DEFAULT, 2);
	err_putstr_fd(" - ", 2);
	err_putstr_fd(log, 2);
	err_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}

//Ne pas oublier de faire en sorte que les printfs impriment dans la sortie d'erreur
int	err_return(int value, char *log, int level)
{
	int	ilev;

	ilev = 0;
	if (value) 
	{
		printf("\n");
		while (ilev++ < level)
			printf("\t");
		printf("%sError L%d\n%s", "\033[4m\033[1;91m", level, F_DEFAULT);
		while (--ilev > 0)
			printf("\t");
		printf("%s\n", log);
	}
	return (value);
}
