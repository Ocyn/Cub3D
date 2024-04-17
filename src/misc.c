/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:24:18 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 17:35:53 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	misc_clear_screen(t_data *data)
{
	long long	x;
	long long	y;

	y = 0;
	if (!data)
		return ;
	while (y <= data->mlx.win_h)
	{
		x = 0;
		while (x <= data->mlx.win_w)
		{
			re_pixeltoimg(data->mlx.game, x, y, 0);
			x++;
		}
		y++;
	}
}

void	misc_opposite_color(int *color)
{
	color[0] = 255 - color[0];
	color[1] = 255 - color[1];
	color[2] = 255 - color[2];
}

int	misc_player_location(t_map map, long long *y, long long *x)
{
	*y = 0;
	*x = 0;
	if (!map.map)
		return (err_return(EXIT_FAILURE, "Memory issue: Map not found", 1));
	while (!ft_strchr(map.map[*y], 'N') \
	&& !ft_strchr(map.map[*y], 'S') \
	&& !ft_strchr(map.map[*y], 'E') \
	&& !ft_strchr(map.map[*y], 'W') && *y <= map.ylen)
		(*y)++;
	while (map.map[*y][*x] != 'N' \
	&& map.map[*y][*x] != 'S' \
	&& map.map[*y][*x] != 'E' \
	&& map.map[*y][*x] != 'W' && map.map[*y][*x])
		(*x)++;
	if (*x == map.xlen && *y == map.ylen)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	return (EXIT_SUCCESS);
}
