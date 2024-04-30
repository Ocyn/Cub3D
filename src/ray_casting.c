/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/30 03:58:43 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rc_minimap_ray(t_data *dt, t_mlx *mlx, int pos[2])
{
	int		y;
	int		cf[2];
	int		ray;

	y = -46;
	while (++y <= 45)
	{
		ray = 10 / mlx->gscale;
		math_coeff_circle(ray, dt->player.angle + y, cf);
		while (pos[0] / 2 + cf[0] - RPS > 0 && pos[1] / 2 + cf[1] - RPS > 0 \
		&& pos[0] / 2 + cf[0] + 1 < pos[0] && pos[1] / 2 + cf[1] + 1 < pos[1] \
		&& *dt->player.y + (cf[1] + (0.5 * RPS)) / mlx->gscale < dt->map.ylen \
		&& *dt->player.y + (cf[1] - (0.5 * RPS)) / mlx->gscale > 0 \
		&& *dt->player.x + (cf[0] + (0.5 * RPS)) / mlx->gscale < dt->map.xlen \
		&& *dt->player.x + (cf[0] - (0.5 * RPS)) / mlx->gscale > 0 \
		&& dt->map.map[(int)round(*dt->player.y + (cf[1] + 0.5) / mlx->gscale)] \
		[(int)round(*dt->player.x + (cf[0] + 0.5) / mlx->gscale)] != '1')
		{
			math_coeff_circle(ray, dt->player.angle + y, cf);
			ray += RPS;
		}
		draw_line_snap(mlx, (size_t[2]){pos[0] / 2, pos[1] / 2} \
		, (size_t[2]){pos[0] / 2 + cf[0], pos[1] / 2 + cf[1]} \
		, 0x0008FF);
	}
}
