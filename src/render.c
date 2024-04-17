/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 17:36:18 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if ((size_t)x >= (size_t)img->width || (size_t)y >= (size_t)img->height)
		return ;
	((int *)img->data)[((y * img->width) + x)] = color;
}

int	re_draw_image(t_data *data)
{
	t_map		*map;
	t_tex		*img;
	int			sfps;

	(void)map;
	map = &data->map;
	img = &data->map.tex_no;
	sfps = db_framepersecond();
	gp_move(data);
	gp_test(data);
	data->mlx.ips++;
	printf("\rFPS [%d] Total [%lld]  |  Player pos (X/Y): %d/%d", sfps, data->mlx.ips, img->lorem, img->ipsum);
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	re_draw_image(data);
	mmap_minimap(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->mlx.game, 0, 0);
	return (EXIT_SUCCESS);
}

int	re_nothing(void *data)
{
	(void)data;
	return (0);
}
