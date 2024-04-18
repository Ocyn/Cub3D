/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:32:21 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/18 18:02:37 by jcuzin           ###   ########.fr       */
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
	return ;
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
	return ;
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
	return ;
}
