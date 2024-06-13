/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/13 19:04:12 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data_struct(&data, argc, argv))
		return (EXIT_FAILURE);
	if (parse_main(&data))
	{
		res_data_struct(&data, 1);
		return (EXIT_FAILURE);
	}
	printf("Color: [%d][%d][%d]\n\n", data.map.floor[0], data.map.floor[1], data.map.floor[2]);
	for (long i = 0; i < data.map.ylen; i++)
		printf("\t\t [%s]\n", data.map.map[i]);
	// graph_main(&data);
	res_data_struct(&data, 1);
	return (EXIT_SUCCESS);
}
