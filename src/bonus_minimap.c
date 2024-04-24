/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/24 20:45:23 by jcuzin           ###   ########.fr       */
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
	minimap->x_y[0] = minimap->win_size[0] / 2;
	minimap->x_y[1] = minimap->win_size[1] / 2;
	minimap->x_y[0] -= player->x_y[0] * mlx->game_scale;
	minimap->x_y[1] -= player->x_y[1] * mlx->game_scale;
	minimap->x_y[0] -= mlx->game_scale / 2;
	minimap->x_y[1] -= mlx->game_scale / 2;
	minimap->angle = player->angle;
	return (EXIT_SUCCESS);
}

int	mmap_area(t_data *data, size_t area[2], size_t cord[2], char c)
{
	int	border;

	(void)data;
	border = 2;
	if (cord[0] + border < area[0] && cord[1] + border < area[1])
	{
		if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			return (conv_rgbtab(255, 0, 0));
		// if (c == '0')
		// 	return (conv_rgb(data->map.floor));
		if (c == '1')
			return (conv_rgbtab(255, 255, 255));
	}
	//return (conv_rgbtab(30, 30, 30));
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
		while (i[0] < (size_t)data->map.xlen)
		{
			color = mmap_area(data, area, (size_t[2]){xy[0] + (i[0] * scale) \
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

void	mmap_draw_hud(t_data *data, int mode)
{
	t_mlx	*mlx;
	//int	coeff[2];

	mlx = &data->mlx;
	if (!mode)
	{
		draw_square(mlx, (size_t[2]){mlx->minimap->win_size[0] + mlx->game_scale \
		, mlx->minimap->win_size[1] + mlx->game_scale}, (size_t[2]){mlx->minimap->win_pos[0] \
		, mlx->minimap->win_pos[1]} \
		, conv_rgbtab(30, 30, 30));
		draw_square(mlx, (size_t[2]){mlx->minimap->win_size[0], mlx->minimap->win_size[1]} \
		, (size_t[2]){mlx->minimap->win_pos[0], mlx->minimap->win_pos[1]}, 0);
	}
	if (mode == 1)
	{
		draw_square(mlx, (size_t[2]){mlx->game_scale, mlx->game_scale} \
		, (size_t[2]){mlx->minimap->win_size[0] / 2 - (mlx->game_scale / 2) \
		, mlx->minimap->win_size[1] / 2 - (mlx->game_scale / 2)} \
		, conv_rgbtab(81, 254, 0));
		// math_coeff_circle(mlx->speed, data->player.angle, coeff);
		// draw_line_snap(mlx, (size_t[2]){mlx->win_wmid, mlx->win_hmid} \
		// , (size_t[2]){mlx->win_wmid + coeff[0], mlx->win_hmid + coeff[1]}, conv_rgbtab(255, 255, 255));
	}
}

int	mmap_minimap(t_data *data)
{
	t_mlx	*mlx;

	(void)data;
	mlx = &data->mlx;
	mmap_move(data);
	mmap_draw_hud(data, 0);
	mmap_draw_map(data, (size_t[2]){mlx->minimap->win_size[0], mlx->minimap->win_size[1]}, mlx->game_scale \
	, (size_t[2]){*mlx->minimap->x, *mlx->minimap->y});
	mmap_draw_hud(data, 1);
	return (EXIT_SUCCESS);
}
