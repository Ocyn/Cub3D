/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/30 02:22:45 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rc_minimap_ray(t_data *data, t_mlx *mlx, int pos[2])
{
	int		y;
	int		coeff[2];
	int		ray;

	y = -45;
	ft_memset(coeff, 0, 2);
	while (y < 45)
	{
		ray = mlx->game_scale / 2;
		while (pos[0] / 2 + coeff[0] - 2 > 0 && pos[1] / 2 + coeff[1] - 2 > 0 \
		&& pos[0] / 2 + coeff[0] + 2 < pos[0] \
		&& pos[1] / 2 + coeff[1] + 2 < pos[1] \
		&& data->map.map[(int)round(*data->player.y + (coeff[1] - 0.5) / mlx->game_scale)] \
		[(int)round(*data->player.x + (coeff[0] - 0.5) / mlx->game_scale)] != '1')
			math_coeff_circle(ray++, data->player.angle + y, coeff);
		math_coeff_circle(ray - 1, data->player.angle + y, coeff);
		draw_line_snap(mlx, (size_t[2]){pos[0] / 2, pos[1] / 2} \
		, (size_t[2]){pos[0] / 2 + coeff[0], pos[1] / 2 + coeff[1]} \
		, 0x0008FF);
		y += 4;
	}
	return (EXIT_SUCCESS);
}
