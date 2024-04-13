/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bindings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 09:01:33 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_keybinds(int key, t_data *data)
{
	db_keylog(key);
	if (key == ESC_KEY)
		graph_close(data);
	if (key == A_KEY || key == Q_KEY || key == LEFT_ARROW_KEY)
		data->map.tex_no.lorem -= 10;
	if (key == D_KEY || key == RIGHT_ARROW_KEY)
		data->map.tex_no.lorem += 10;
	if (key == Z_KEY || key == W_KEY || key == UP_ARROW_KEY)
		data->map.tex_no.ipsum -= 10;
	if (key == S_KEY || key == DOWN_ARROW_KEY)
		data->map.tex_no.ipsum += 10;
	if (key == TAB_KEY)
		printf("Tab\t[%d]\n", key);
	return ;
}
