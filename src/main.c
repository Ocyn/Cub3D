/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 22:16:27 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	/* DEBUG */	printf("\nCUB3D #####\n\n");
	if (argc != 2 || !argv)
		return (EXIT_FAILURE);
	if (init_data_struct(&data, argc, argv))
		return (EXIT_FAILURE);
	if (pa_main(&data))
		return (EXIT_FAILURE);
	db_readfile(argv[1]);
	return (EXIT_SUCCESS);
}
