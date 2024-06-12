/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:23:32 by aammirat          #+#    #+#             */
/*   Updated: 2024/06/12 14:56:08 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mmap_area(size_t area[2], size_t cord[2], char c)
{
	if (cord[0] < area[0] && cord[1] < area[1])
	{
		if (c == '1')
			return (0xFFFFFF);
		if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			return (0xFF0000);
	}
	return (0x0);
}

void	rc_minimap_ray(t_data *dt, t_mlx *mlx, int pos[2])
{
	int		y;
	int		cf[2];
	int		ray;

	y = (mlx->fov / 2) * -1;
	while (++y <= mlx->fov / 2)
	{
		ray = 10 / mlx->gscale;
		math_circle(ray, (dt->player.angle + y) + 180, cf);
		while (pos[0] / 2 + cf[0] - RPS > 0 && pos[1] / 2 + cf[1] - RPS > 0 \
		&& pos[0] / 2 + cf[0] + 1 < pos[0] && pos[1] / 2 + cf[1] + 1 < pos[1] \
		&& *dt->player.y + (cf[1] + (0.5 * RPS)) / mlx->gscale < dt->map.ylen \
		&& *dt->player.y + (cf[1] - (0.5 * RPS)) / mlx->gscale > 0 \
		&& *dt->player.x + (cf[0] + (0.5 * RPS)) / mlx->gscale < dt->map.xlen \
		&& *dt->player.x + (cf[0] - (0.5 * RPS)) / mlx->gscale > 0 \
		&& dt->map.map[(int)round(*dt->player.y + (cf[1] + 0.5) / mlx->gscale)] \
		[(int)round(*dt->player.x + (cf[0] + 0.5) / mlx->gscale)] != '1')
		{
			math_circle(ray, (dt->player.angle + y) + 180, cf);
			ray += mlx->rps;
		}
		draw_line_snap(mlx, (size_t[2]){pos[0] / 2, pos[1] / 2} \
		, (size_t[2]){pos[0] / 2 + cf[0], pos[1] / 2 + cf[1]} \
		, 0x0008FF);
	}
}
