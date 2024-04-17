/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 14:58:06 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline int	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	(void)x;
	(void)y;
	(void)color;
	if (!img || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (EXIT_FAILURE);
	((int *)img->data)[((y * img->width) + x)] = color;
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	t_map		*map;
	t_tex		*img;
	size_t		sfps;

	(void)map;
	map = &data->map;
	img = &data->map.tex_no;
	sfps = db_framepersecond(data->ips);
	gp_move(data);
	gp_test(data);
	mlx_put_image_to_window(data->mlxinit, data->win, data->game, 0, 0);
	data->ips++;
	printf("\rFPS [%lld][%zu]\t\tMouse (X/Y): %d/%d", data->ips, sfps, img->lorem, img->ipsum);
	return (EXIT_SUCCESS);
}

int	re_nothing(void *data)
{
	(void)data;
	return (0);
}
