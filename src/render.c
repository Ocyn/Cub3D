/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 19:12:48 by jcuzin           ###   ########.fr       */
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
	long		pmapx;
	long		pmapy;
	t_map		*map;
	t_player	*player;
	int			sfps;

	(void)map;
	map = &data->map;
	player = &data->player;
	sfps = db_framepersecond();
	gp_move(data);
	gp_test(data);
	data->mlx.ips++;
	pmapx = data->mlx.win_w;
	pmapy = data->mlx.win_h;
	printf("\rFPS [%d] Total [%lld] | Player [%f][%f] -> [%ld][%ld]\r", sfps, data->mlx.ips, player->x, player->y, pmapx, pmapy);
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
