/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:21 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/25 23:02:22 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	draw_square(t_mlx *mlx, size_t size[2], size_t xy[2], int color)
{
	size_t	i[2];

	i[1] = 0;
	while (i[1] < size[1])
	{
		i[0] = 0;
		while (i[0] < size[0])
		{
			re_pixeltoimg(mlx->game, xy[0] + i[0], xy[1] + i[1], color);
			i[0]++;
		}
		i[1]++;
	}
}

inline void	draw_line_snap(t_mlx *mlx, size_t one[2], size_t two[2], int color)
{
	int	x[2];
	int	y[2];
	int	angle[2];

	x[0] = abs((int)two[0] - (int)one[0]);
	y[0] = abs((int)two[1] - (int)one[1]);
	x[1] = (one[0] < two[0]);
	y[1] = (one[1] < two[1]);
	if (!x[1])
		x[1] = -1;
	if (!y[1])
		y[1] = -1;
	angle[0] = x[0] - y[0];
	while (one[0] != two[0] || one[1] != two[1])
	{
		re_pixeltoimg(mlx->game, one[0], one[1], color);
		angle[1] = angle[0] * 2;
		if (angle[1] > -y[0])
		{
			angle[0] -= y[0];
			one[0] += x[1];
		}
		if (angle[1] < x[0])
		{
			angle[0] += x[0];
			one[1] += y[1];
		}
	}
}

inline void	draw_square_snap(t_mlx *mlx, size_t one[2], size_t two[2], int color)
{
	size_t	x;

	if (one[0] >= two[0] || one[1] >= two[1])
		return ;
	x = one[0];
	while (one[1] <= two[1])
	{
		one[0] = x;
		while (one[0] <= two[0])
		{
			re_pixeltoimg(mlx->game, one[0], one[1], color);
			one[0]++;
		}
		one[1]++;
	}
}

inline void	draw_square_snap2(t_mlx *mlx, size_t one[2], size_t two[2], int color)
{
	t_img	*img;

	img = ((t_img *)mlx->game);
	ft_memset(img->data + ((img->width * one[1]) + one[0]) \
	, (int)color, 4 * (img->width * two[1]) + two[0]);
}

inline void	draw_grid_sq(t_mlx *mlx, size_t size[2], size_t xy[2], int color)
{
	size_t	i[2];

	i[1] = 0;
	draw_square(mlx, size, xy, 0);
	while ((i[1] * (size[1] / 10)) < size[1])
	{
		i[0] = 0;
		while ((i[0] * (size[1] / 10)) < size[0])
		{
			draw_square(mlx, (size_t[2]){size[0] / 10 - 1, size[1] / 10 - 1} \
			, (size_t[2]){xy[0] + (i[0] * (size[0] / 10)) \
			, xy[1] + (i[1] * (size[1] / 10))}, color);
			i[0]++;
		}
		i[1]++;
	}
}

inline void	draw_grid_tab(t_mlx *mlx, char **tab, int scale, size_t xy[2])
{
	int		color;
	size_t	line;
	size_t	i[2];

	i[1] = 0;
	line = ft_strlen(tab[0]);
	while (tab[i[1]])
	{
		i[0] = 0;
		draw_square(mlx, (size_t[2]){scale * line, scale}, (size_t[2]){xy[0], xy[1] + (i[1] * scale)}, conv_rgbtab(20, 20, 20));
		while (tab[i[1]][i[0]])
		{
			color = conv_rgbtab(255, 255, 255);
			if (tab[i[1]][i[0]] != '0')
			{
				draw_square(mlx, (size_t[2]){scale - 1, scale - 1} \
				, (size_t[2]){xy[0] + (i[0] * scale) \
				, xy[1] + (i[1] * scale)}, color);
			}
			i[0]++;
		}
		i[1]++;
	}
}
