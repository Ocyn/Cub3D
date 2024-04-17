/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 19:01:26 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_draw_player(t_data *data)
{
	long	y;
	long	x;

	y = ((data->mlx.win_h / 6) / 2) - 5;
	while (y <= ((data->mlx.win_h / 6) / 2) + 5)
	{
		x = ((data->mlx.win_w / 6) / 2) - 5;
		while (x <= ((data->mlx.win_w / 6) / 2) + 5)
		{
			re_pixeltoimg(data->mlx.game, x, y, conv_rgbtab(255, 255, 255));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	mmap_draw_map(t_data *data)
{
	long	y;
	long	x;

	y = 0;
	while (y <= data->mlx.win_h / 6)
	{
		x = 0;
		while (x <= data->mlx.win_w / 6)
		{
			re_pixeltoimg(data->mlx.game, x, y, conv_rgbtab(150, 150, 150));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	mmap_draw_border(t_data *data)
{
	long	y;
	long	x;

	y = 0;
	while (y <= data->mlx.win_h / 6)
	{
		x = 0;
		while (x <= data->mlx.win_w / 6)
		{
			re_pixeltoimg(data->mlx.game, x, y, conv_rgbtab(0, 0, 0));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	mmap_minimap(t_data *data)
{
	(void)data;
	mmap_draw_map(data);
	mmap_draw_player(data);
	return (EXIT_SUCCESS);
}
