/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:36 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/19 16:33:43 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_move(t_data *data)
{
	t_player	*player;
	t_mlx		*mlx;

	player = &data->player;
	mlx = &data->mlx;
	if (!player->b_move)
		return (EXIT_SUCCESS);
	mlx->minimap_y = mlx->minimap_size[1] / 2;
	mlx->minimap_x = mlx->minimap_size[0] / 2;
	mlx->minimap_y -= player->y * mlx->game_scale;
	mlx->minimap_x -= player->x * mlx->game_scale;
	mlx->minimap_y -= mlx->game_scale / 2;
	mlx->minimap_x -= mlx->game_scale / 2;
	mlx->minimap_angle = player->angle_rot;
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
	// return (conv_rgbtab(30, 30, 30));
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

void	mmap_draw_hud(t_mlx *mlx, int mode)
{
	if (!mode)
	{
		draw_square(mlx, (size_t[2]){mlx->minimap_size[0] + mlx->game_scale \
		, mlx->minimap_size[1] + mlx->game_scale}, (size_t[2]){mlx->minimap_pos[0] \
		, mlx->minimap_pos[1]}, conv_rgbtab(30, 30, 30));
	}
	if (mode == 1)
	{
		draw_square(mlx, (size_t[2]){mlx->game_scale, mlx->game_scale} \
		, (size_t[2]){mlx->minimap_size[0] / 2 - (mlx->game_scale / 2), mlx->minimap_size[1] / 2 - (mlx->game_scale / 2)} \
		, conv_rgbtab(81, 254, 0));
	}
}

int	mmap_minimap(t_data *data)
{
	t_mlx	*mlx;

	(void)data;
	mlx = &data->mlx;
	mmap_move(data);
	mmap_draw_hud(mlx, 0);
	draw_square(mlx, (size_t *)mlx->minimap_size, (size_t *)mlx->minimap_pos, 0);
	mmap_draw_map(data, (size_t *)mlx->minimap_size, mlx->game_scale \
	, (size_t[2]){(mlx->minimap_x), (mlx->minimap_y)});
	mmap_draw_hud(mlx, 1);
	return (EXIT_SUCCESS);
}
