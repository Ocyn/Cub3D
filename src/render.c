/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 17:51:14 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	re_draw_environnment(t_data *data, int full)
{
	(void)full;
	draw_square(&data->mlx \
	, (size_t[2]){data->minimap.size[0] + data->mlx.gscale, 0} \
	, (size_t[2]){data->mlx.win_w, data->minimap.size[1] + data->mlx.gscale} \
	, data->map.sky_h);
	misc_fill_screen(data->mlx.game \
	, data->minimap.size[1] + data->mlx.gscale \
	, data->mlx.win_hmid - 1, data->map.sky_h);
	misc_fill_screen(data->mlx.game \
	, data->mlx.win_hmid, data->mlx.win_hmid - 1, data->map.floor_h);
}

void	re_pixel_column_utils(double *color, t_tex *buf, t_data *data)
{
	if (color[0] == 1)
		*buf = data->map.tex_we;
	if (color[0] == 2)
		*buf = data->map.tex_ea;
	if (color[0] == 3)
		*buf = data->map.tex_no;
	if (color[0] == 4)
		*buf = data->map.tex_so;
}

inline void	re_pixel_column(t_data *data, double *col, int x, double const di)
{
	int		i;
	t_tex	buf;

	i = (data->mlx.win_hmid) - di;
	re_pixel_column_utils(col, &buf, data);
	if (i < 0)
		i = 0;
	while (i < (data->mlx.win_hmid) + di && i < data->mlx.win_h)
	{
		if ((col[0] == 1 || col[0] == 4) && (i > 0 && i < \
		data->mlx.win_h) && (col[1] * buf.wi >= 0 && col[1] * buf.wi <= buf.wi))
		{
			re_pixeltoimg(data->mlx.game, x, i, \
			re_take_img_pixel(buf.id, col[1] * buf.wi, ((float)(i - \
			((data->mlx.win_hmid) - di)) / (di * 2)) * buf.he));
		}
		else if ((col[0] == 2 || col[0] == 3) && (i > 0 && i < \
		data->mlx.win_h) && (col[1] * buf.wi >= 0 && col[1] * buf.wi <= buf.wi))
		{
			re_pixeltoimg(data->mlx.game, x, i, \
			re_take_img_pixel(buf.id, buf.wi - (col[1] * buf.wi) - 1, \
			((float)(i - ((data->mlx.win_hmid) - di)) / (di * 2)) * buf.he));
		}
		i++;
	}
}

int	re_events_loop(t_data *data)
{
	double	color[2];
	double	dist;
	double	angle;
	int		i;

	if (!data)
		return (EXIT_FAILURE);
	i = -1;
	gp_move(data);
	re_draw_environnment(data, 1);
	while (++i < data->mlx.win_w)
	{
		angle = (double)(((double)data->player.angle) \
		+ (i - (double)data->mlx.win_w / 2) \
		* (double)data->mlx.fov / data->mlx.win_w);
		dist = rc_main(data, angle, color) / (data->mlx.fov * 0.0128);
		re_pixel_column(data, color, i, dist / 2);
	}
	mmap_minimap(data);
	graph_window_bench(data, &data->mlx);
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	long	fps;

	if (!data)
		return (EXIT_FAILURE);
	fps = data->mlx.fps + 1;
	if (fps > 60)
		data->mlx.rps = 1;
	else if (fps > 30)
		data->mlx.rps = 4;
	else if (fps > 10)
		data->mlx.rps = 8;
	else if (fps > 5)
		data->mlx.rps = 16;
	re_events_loop(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win \
	, data->mlx.game, 0, 0);
	return (EXIT_SUCCESS);
}
