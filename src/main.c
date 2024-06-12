/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/12 14:54:42 by aammirat         ###   ########.fr       */
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
	graph_main(&data);
	res_data_struct(&data, 1);
	return (EXIT_SUCCESS);
}
