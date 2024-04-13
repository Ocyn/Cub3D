/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 13:18:51 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if (!img)
		return (EXIT_FAILURE);
	(void)x;
	(void)y;
	(void)color;
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	t_map		*map;
	t_tex		*img;

	(void)map;
	map = &data->map;
	img = &data->map.tex_no;
	graph_test(data);
	mlx_put_image_to_window(data->mlxinit, data->win, img->id, img->lorem, img->ipsum);
	data->ips++;
	printf("\rips [%lld]\t\tMouse (X/Y): %d/%d", data->ips, img->lorem, img->ipsum);
	return (EXIT_SUCCESS);
}

int	re_nothing(void *data)
{
	(void)data;
	return (0);
}
