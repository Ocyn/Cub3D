/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 05:21:07 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_gameplay(int key, t_data *data)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 2));
	if (key == ESC_KEY)
		graph_close(data);
	if (key == A_KEY || key == Q_KEY || key == LEFT_ARROW_KEY)
		printf("Left\t[%d]\n", key);
	if (key == D_KEY || key == RIGHT_ARROW_KEY)
		printf("Right\t[%d]\n", key);
	if (key == Z_KEY || key == W_KEY || key == UP_ARROW_KEY)
		printf("Forward\t[%d]\n", key);
	if (key == S_KEY || key == DOWN_ARROW_KEY)
		printf("Backward\t[%d]\n", key);
	if (key == TAB_KEY)
		printf("Tab\t[%d]\n", key);
	return (EXIT_SUCCESS);
}
