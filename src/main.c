/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 16:14:18 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ascii_title(char *tab)
{
	printf("%s\n", F_DEFAULT);
	printf("%s_________________________________________\n\n", tab);
	printf("%s%s ██████ ██    ██ ██████  ██████╗ ██████╗ \n", tab, F_LGREY2);
	printf("%s%s██      ██    ██ ██   ██ ╚════██╗██╔══██╗\n", tab, F_WHITE);
	printf("%s%s██      ██    ██ █████    █████╔╝██║  ██║\n", tab, F_BLACK);
	printf("%s%s██      ██    ██ ██   ██  ╚═══██╗██║  ██║\n", tab, F_DRED);
	printf("%s%s ██████  ██████  ██████  ██████╔╝██████╔╝\n", tab, F_RED2);
	printf("%s%s                         ╚═════╝ ╚═════╝ \n", tab, F_WHITE);
	printf("%s%s          By Jcuzin x Aammirat          \n", tab, F_BOLD);
	printf("%s%s_________________________________________\n", tab, F_WHITE);
	printf("%s\n", F_DEFAULT);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ascii_title("");
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
