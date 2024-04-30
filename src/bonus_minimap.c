/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/30 02:14:31 by jcuzin           ###   ########.fr       */
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
	minimap->x_y[0] -= player->x_y[0] * mlx->game_scale;
	minimap->x_y[1] -= player->x_y[1] * mlx->game_scale;
	minimap->x_y[0] -= mlx->game_scale / 2;
	minimap->x_y[1] -= mlx->game_scale / 2;
	minimap->angle = player->angle + 90;
	return (EXIT_SUCCESS);
}

int	mmap_area(size_t area[2], size_t cord[2], char c)
{
	if (cord[0] < area[0] && cord[1] < area[1])
	{
		if (c == '1')
			return (0xFFFFFF);
		if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			return (0xFF0000);
		// return (conv_rgbtab(30, 30, 30));
		// if (c == '0')
		// 	return (conv_rgb(data->map.floor));
	}
	// else
	// 	return (conv_rgbtab(30, 30, 30));
	return (0x0);
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
	pmark[0] = mlx->minimap->size[0] / 2 - (mlx->game_scale / 2);
	pmark[1] = mlx->minimap->size[1] / 2 - (mlx->game_scale / 2);
	draw_square(mlx, pmark, (size_t[2]){pmark[0] + mlx->game_scale \
	, pmark[1] + mlx->game_scale}, 0x51FE00);
	rc_minimap_ray(data, mlx, mlx->minimap->size);
	math_coeff_circle(mlx->game_scale, data->player.angle, coeff);
	draw_line_snap(mlx, (size_t[2]){mlx->minimap->size[0] / 2, mlx->minimap->size[1] / 2} \
	, (size_t[2]){mlx->minimap->size[0] / 2 + coeff[0], mlx->minimap->size[1] / 2 + coeff[1]}, 0xFFFFFF);
}

void	mmap_draw_hud(t_data *data)
{
	t_mlx		*mlx;

	mlx = &data->mlx;
	mmap_player(data);
	draw_square(mlx, (size_t[2]){mlx->minimap->size[0], 0} \
	, (size_t[2]){mlx->minimap->size[0] + mlx->game_scale, mlx->minimap->size[1]} \
	, 0x121212);
	draw_square(mlx, (size_t[2]){0, mlx->minimap->size[1]} \
	, (size_t[2]){mlx->minimap->size[0] + mlx->game_scale, mlx->minimap->size[1] + mlx->game_scale} \
	, 0x121212);
}

int	mmap_minimap(t_data *data)
{
	t_mlx	*mlx;

	(void)data;
	mlx = &data->mlx;
	mmap_move(data);
	draw_square(mlx, (size_t[2]){0, 0} \
	, (size_t[2]){mlx->minimap->size[0], mlx->minimap->size[1]}, 0x0);
	mmap_draw_map(data, (size_t[2]){mlx->minimap->size[0], mlx->minimap->size[1]}, mlx->game_scale \
	, (long[2]){*mlx->minimap->x, *mlx->minimap->y});
	mmap_draw_hud(data);
	return (EXIT_SUCCESS);
}
