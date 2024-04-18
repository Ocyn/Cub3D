/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/18 19:05:01 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_draw_player(t_data *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

int	mmap_area(size_t area[2], size_t cord[2], char c)
{
	(void)area;
	if (c != '0')
	{
		if (cord[0] < area[0] && cord[1] < area[1])
			return (conv_rgbtab(255, 255, 255));
		// else
		// 	return (conv_rgbtab(50, 50, 50));
	}
	return (0);
}

inline void	mmap_draw_map(t_data *data, size_t area[2], int scale, size_t xy[2])
{
	int		color;
	size_t	line;
	size_t	i[2];

	i[1] = 0;
	line = ft_strlen(data->map.map[0]);
	while (i[1] < (size_t)data->map.ylen)
	{
		i[0] = 0;
		// draw_square(&data->mlx, (size_t[2]){scale * line, scale} \
		// , (size_t[2]){xy[0], xy[1] + (i[1] * scale)}, 0);
		while (i[0] < (size_t)data->map.xlen)
		{
			color = mmap_area(area, (size_t[2]){xy[0] + (i[0] * scale) \
			, xy[1] + (i[1] * scale)}, data->map.map[i[1]][i[0]]);
			if (color)
			{
				draw_square(&data->mlx, (size_t[2]){scale - 1, scale - 1} \
				, (size_t[2]){xy[0] + (i[0] * scale) \
				, xy[1] + (i[1] * scale)}, color);
			}
			i[0]++;
		}
		i[1]++;
	}
}

int	mmap_draw_hud(t_data *data)
{
	long	y;
	long	x;

	y = -1;
	while (++y <= data->mlx.win_h / 6)
	{
		x = -1;
		while (++x <= data->mlx.win_w / 6)
		{
			if (y == 0 || x == 0 \
			|| x == data->mlx.win_w / 6 || y == data->mlx.win_h / 6)
				re_pixeltoimg(data->mlx.game, x, y, conv_rgbtab(20, 0, 255));
		}
	}
	draw_square(&data->mlx, (size_t[2]){10, 10} \
	, (size_t[2]){data->mlx.win_w / 12 - 5, data->mlx.win_h / 12 - 5} \
	, conv_rgbtab(255, 0, 178));
	return (EXIT_SUCCESS);
}

int	mmap_minimap(t_data *data)
{
	size_t	area[2] = {data->mlx.win_w / 6, data->mlx.win_h / 6};
	size_t	cord[2] = {0, 0};

	(void)data;
	draw_square(&data->mlx, area, cord, 0);
	mmap_draw_map(data, area, 10, (size_t[2]){data->player.x, data->player.y});
	mmap_draw_hud(data);
	return (EXIT_SUCCESS);
}
