/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/10 13:01:06 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	db_ascii_title("");
	if (init_data_struct(&data, argc, argv))
		return (EXIT_FAILURE);
	if (parse_main(&data))
	{
		res_data_struct(&data, 1);
		return (EXIT_FAILURE);
	}
	//db_showmap(data.map, 0);
	//db_showplayer(data.player);
	res_data_struct(&data, 1);
	return (EXIT_SUCCESS);
}
