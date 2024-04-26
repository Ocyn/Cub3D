/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/26 05:37:36 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if ((size_t)x >= (size_t)img->width || (size_t)y >= (size_t)img->height)
		return ;
	((int *)img->data)[((y * img->width) + x)] = color;
}

inline void	re_draw_environnment(t_data *data, int full)
{
	(void)full;
	draw_square(&data->mlx \
	, (size_t[2]){data->minimap.size[0] + data->mlx.game_scale, 0} \
	, (size_t[2]){data->mlx.win_w, data->minimap.size[1] + data->mlx.game_scale} \
	, data->map.sky_h);
	misc_fill_screen(data->mlx.game \
	, data->minimap.size[1] + data->mlx.game_scale \
	, data->mlx.win_hmid - 1, data->map.sky_h);
	misc_fill_screen(data->mlx.game \
	, data->mlx.win_hmid, data->mlx.win_hmid - 1, data->map.floor_h);
}

inline void	re_draw_wall(t_data *data)
{
	int		column;

	column = 0;
	while (column < data->mlx.win_w)
	{
		re_pixel_column(data, 0xFF00AE, column, 100);
		column += data->mlx.fov;
	}
	return ;
}

inline void	re_pixel_column(t_data *data, int color, int x, int distance)
{
	// draw_square(&data->mlx, (size_t[2]){x, 0} \
	// , (size_t[2]){x + data->mlx.fov, data->mlx.win_hmid - distance}, 0x0);
	draw_square(&data->mlx, (size_t[2]){x, data->mlx.win_hmid - distance} \
	, (size_t[2]){x + data->mlx.fov, data->mlx.win_hmid + distance}, color);
	// draw_square(&data->mlx, (size_t[2]){x, data->mlx.win_hmid + distance} \
	// , (size_t[2]){x + data->mlx.fov, data->mlx.win_h}, 0x0);
}

int	re_events_loop(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	gp_move(data);
	//sb_circle(data);
	//re_draw_environnment(data, 0);
	//draw_square(&data->mlx, (size_t[2]){500, 500}, (size_t[2]){800, 800}, 0xFF00AE);
	//draw_square2(&data->mlx, (size_t[2]){500, 500}, (size_t[2]){800, 800}, 0xFF00AE);
	//misc_fill_screen(data->mlx.game, data->mlx.win_hmid, 100, 0xFF00AE);
	re_draw_wall(data);
	mmap_minimap(data);
	db_game_monitoring(data);
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	re_events_loop(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->mlx.game, 0, 0);
	return (EXIT_SUCCESS);
}
