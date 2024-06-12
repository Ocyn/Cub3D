/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/05 17:01:57 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_move(t_data *data)
{
	t_player	*player;
	t_mlx		*mlx;
	t_minimap	*minimap;

	player = &data->player;
	mlx = &data->mlx;
	minimap = &data->minimap;
	if (!player->b_move)
		return (EXIT_SUCCESS);
	minimap->x_y[0] = minimap->size[0] / 2;
	minimap->x_y[1] = minimap->size[1] / 2;
	minimap->x_y[0] -= player->x_y[0] * mlx->gscale;
	minimap->x_y[1] -= player->x_y[1] * mlx->gscale;
	minimap->x_y[0] -= mlx->gscale / 2;
	minimap->x_y[1] -= mlx->gscale / 2;
	minimap->angle = player->angle + 90;
	return (EXIT_SUCCESS);
}

inline void	mmap_draw_map(t_data *data, size_t area[2], int scale, long xy[2])
{
	int		color;
	size_t	i[2];
	long	pmark[2];

	i[1] = 0;
	while (i[1] < (size_t)data->map.ylen)
	{
		i[0] = 0;
		while (i[0] < (size_t)data->map.xlen)
		{
			pmark[0] = xy[0] + (i[0] * scale);
			pmark[1] = xy[1] + (i[1] * scale);
			color = mmap_area(area, (size_t *)pmark, data->map.map[i[1]][i[0]]);
			if (color)
				draw_square(&data->mlx, (size_t[2]){pmark[0] + 1, pmark[1] + 1} \
				, (size_t[2]){pmark[0] + scale, pmark[1] + scale - 1}, color);
			i[0]++;
		}
		i[1]++;
	}
}

void	mmap_player(t_data *data)
{
	t_mlx		*mlx;
	size_t		pmark[2];
	int			coeff[2];

	mlx = &data->mlx;
	pmark[0] = mlx->minimap->size[0] / 2 - (mlx->gscale / 2);
	pmark[1] = mlx->minimap->size[1] / 2 - (mlx->gscale / 2);
	draw_square(mlx, pmark, (size_t[2]){pmark[0] + mlx->gscale \
	, pmark[1] + mlx->gscale}, 0x51FE00);
	math_circle(mlx->gscale, data->player.angle, coeff);
	draw_line_snap(mlx, (size_t[2]){mlx->minimap->size[0] / 2, \
	mlx->minimap->size[1] / 2}, (size_t[2]){mlx->minimap->size[0] / \
	2 + coeff[0], mlx->minimap->size[1] / 2 + coeff[1]}, 0xFFFFFF);
}

void	mmap_draw_hud(t_data *data)
{
	t_mlx		*mlx;

	mlx = &data->mlx;
	mmap_player(data);
	draw_square(mlx, (size_t[2]){mlx->minimap->size[0], 0} \
	, (size_t[2]){mlx->minimap->size[0] + mlx->gscale, mlx->minimap->size[1]} \
	, 0x121212);
	draw_square(mlx, (size_t[2]){0, mlx->minimap->size[1]} \
	, (size_t[2]){mlx->minimap->size[0] + mlx->gscale, \
	mlx->minimap->size[1] + mlx->gscale}, 0x121212);
}

int	mmap_minimap(t_data *data)
{
	t_mlx	*mlx;
	long	buf[2];

	(void)data;
	mlx = &data->mlx;
	buf[0] = *mlx->minimap->x;
	buf[1] = *mlx->minimap->y;
	mmap_move(data);
	draw_square(mlx, (size_t[2]){0, 0} \
	, (size_t[2]){mlx->minimap->size[0], mlx->minimap->size[1]}, 0x0);
	rc_minimap_ray(data, mlx, mlx->minimap->size);
	mmap_draw_map(data, (size_t[2]){mlx->minimap->size[0], \
	mlx->minimap->size[1]}, mlx->gscale, buf);
	mmap_draw_hud(data);
	return (EXIT_SUCCESS);
}
