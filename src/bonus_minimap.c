/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 17:35:27 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_init(t_data *data, int *pos, int *size, int *bkgnd)
{
	int	color[3];

	(void)data;
	*bkgnd = 0;
	pos[0] = 10;
	pos[1] = 10;
	size[0] = 10;
	size[1] = 10;
	color[0] = data->map.roof[0];
	color[1] = data->map.roof[1];
	color[2] = data->map.roof[2];
	misc_opposite_color(color);
	*bkgnd = conv_rgb(color);
	return (EXIT_SUCCESS);
}

int	mmap_draw_square(t_data *data, long width, long height, int color)
{
	long	y;
	long	x;

	y = 20;
	while (y <= height)
	{
		x = 40;
		while (x <= width)
		{
			re_pixeltoimg(data->mlx.game, x, y, color);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	mmap_minimap(t_data *data)
{
	int	pos[2];
	int	size[2];
	int	bkgnd;

	(void)data;
	mmap_init(data, pos, size, &bkgnd);
	mmap_draw_square(data, data->mlx.win_w / 6, data->mlx.win_h / 6, bkgnd);
	return (EXIT_SUCCESS);
}
