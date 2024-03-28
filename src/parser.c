/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 21:27:22 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pa_checkfile(char *file)
{
	int	fd;

	fd = 0;
	if (!file)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		err_stderr(1);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	pa_main(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (pa_checkfile(data->arg_tab[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
